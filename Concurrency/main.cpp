#include <condition_variable>

#include <chrono>
#include <deque>
#include <iostream>
#include <memory>
#include <mutex>
#include <random>
#include <semaphore>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

// ============= 有界 MPMC 队列（可换成 moodycamel::ConcurrentQueue） =============
template<class T>
class BoundedQueue {
  public:
    explicit BoundedQueue(size_t cap)
        : cap_(cap) {}

    // 生产：满则等待；若已关闭返回 false
    bool push(T v) {
        std::unique_lock<std::mutex> lk(m_);
        not_full_.wait(lk, [&] { return closed_ || q_.size() < cap_; });
        if (closed_) return false;
        q_.emplace_back(std::move(v));
        not_empty_.notify_one();
        return true;
    }

    // 消费：空则等待；若已关闭且为空返回 false
    bool pop(T &out) {
        std::unique_lock<std::mutex> lk(m_);
        not_empty_.wait(lk, [&] { return closed_ || !q_.empty(); });
        if (q_.empty()) return false; // closed and empty
        out = std::move(q_.front());
        q_.pop_front();
        not_full_.notify_one();
        return true;
    }

    // 关闭：唤醒所有等待者，后续 push/pop 按规则返回
    void close() {
        std::scoped_lock<std::mutex> lk(m_);
        closed_ = true;
        not_full_.notify_all();
        not_empty_.notify_all();
    }

  private:
    size_t                  cap_;
    std::deque<T>           q_;
    std::mutex              m_;
    std::condition_variable not_full_, not_empty_;
    bool                    closed_ = false;
};

// ============= 消息/实体定义 =============
struct TableRequest {
    int                                    customer_id;
    std::shared_ptr<std::binary_semaphore> dish_sem; // 顾客专属“上菜”信号
};

struct Order {
    int                                    order_id;
    int                                    customer_id;
    std::shared_ptr<std::binary_semaphore> dish_sem;
};

struct DishReady {
    int                                    order_id;
    std::shared_ptr<std::binary_semaphore> dish_sem;
};

// ============= 随机延时工具 =============
struct RandDelay {
    std::mt19937 rng{std::random_device{}()};

    template<class Rep, class Period>
    void sleep_between(std::chrono::duration<Rep, Period> lo, std::chrono::duration<Rep, Period> hi) {
        using Ms = std::chrono::milliseconds;
        std::uniform_int_distribution<int> dist(
            (int) std::chrono::duration_cast<Ms>(lo).count(),
            (int) std::chrono::duration_cast<Ms>(hi).count()
        );
        std::this_thread::sleep_for(Ms(dist(rng)));
    }
};

// ============= 主程序 =============
int main() {
    // ---- 可配置参数（可调优/横向扩展） ----
    int const    seat_capacity       = 5;  // 同时可就座顾客数
    int const    num_waiters_taking  = 2;  // 负责点单的服务员
    int const    num_waiters_serving = 2;  // 负责上菜的服务员
    int const    num_chefs           = 2;  // 厨师数
    int const    total_customers     = 16; // 模拟顾客总数
    size_t const Q_READY_TO_ORDER    = 16; // “待点单”队列容量
    size_t const Q_ORDERS            = 32; // 厨房订单队列容量
    size_t const Q_READY_DISH        = 32; // 出菜队列容量

    // ---- 并发原语与队列 ----
    std::counting_semaphore<INT_MAX> seats(seat_capacity); // 席位信号量
    BoundedQueue<TableRequest>       ready_to_order_q(Q_READY_TO_ORDER);
    BoundedQueue<Order>              orders_q(Q_ORDERS);
    BoundedQueue<DishReady>          ready_dishes_q(Q_READY_DISH);

    std::atomic<int> next_order_id{1};

    // ---- 工作线程：服务员（点单）----
    std::vector<std::jthread> waiters_take;
    for (int i = 0; i < num_waiters_taking; ++i) {
        waiters_take.emplace_back([&](std::stop_token) {
            RandDelay rd;
            for (;;) {
                TableRequest req;
                if (!ready_to_order_q.pop(req)) break; // 队列关闭
                int oid = next_order_id.fetch_add(1);
                std::cout << "[Waiter-Take] customer " << req.customer_id
                          << " -> order #" << oid << "\n";
                orders_q.push(Order{oid, req.customer_id, req.dish_sem});
                rd.sleep_between(10ms, 40ms); // 写单/确认等
            }
            std::cout << "[Waiter-Take] exit\n";
        });
    }

    // ---- 工作线程：厨师（做菜）----
    std::vector<std::jthread> chefs;
    for (int i = 0; i < num_chefs; ++i) {
        chefs.emplace_back([&](std::stop_token) {
            RandDelay rd;
            for (;;) {
                Order ord;
                if (!orders_q.pop(ord)) break;
                std::cout << "  [Chef] cooking order #" << ord.order_id
                          << " for customer " << ord.customer_id << "\n";
                rd.sleep_between(120ms, 400ms); // 烹饪耗时
                ready_dishes_q.push(DishReady{ord.order_id, ord.dish_sem});
            }
            std::cout << "  [Chef] exit\n";
        });
    }

    // ---- 工作线程：服务员（上菜）----
    std::vector<std::jthread> waiters_serve;
    for (int i = 0; i < num_waiters_serving; ++i) {
        waiters_serve.emplace_back([&](std::stop_token) {
            for (;;) {
                DishReady d;
                if (!ready_dishes_q.pop(d)) break;
                std::cout << "[Waiter-Serve] serve order #" << d.order_id << "\n";
                d.dish_sem->release(); // 通知对应顾客“已上菜”
            }
            std::cout << "[Waiter-Serve] exit\n";
        });
    }

    // ---- 顾客线程 ----
    std::vector<std::jthread> customers;
    for (int cid = 1; cid <= total_customers; ++cid) {
        customers.emplace_back([&, cid](std::stop_token) {
            RandDelay rd;
            // 3. 有空位才入座
            seats.acquire();
            std::cout << "[Customer " << cid << "] seated\n";

            // 发起“待点单”，并准备一个个人的“上菜”信号
            auto dish_sem = std::make_shared<std::binary_semaphore>(0);
            ready_to_order_q.push(TableRequest{cid, dish_sem});

            // 6. 等到上菜再用餐
            dish_sem->acquire();
            std::cout << "[Customer " << cid << "] eating...\n";
            rd.sleep_between(120ms, 300ms); // 用餐时间

            // 7. 离开餐厅 -> 归还席位
            seats.release();
            std::cout << "[Customer " << cid << "] leave\n";
        });
    }

    // ---- 收尾：等待顾客结束 -> 依次关闭队列，冲刷流水线 ----
    for (auto &t: customers) t.join();
    ready_to_order_q.close(); // 没有新的点单请求
    for (auto &t: waiters_take) t.join();

    orders_q.close(); // 厨房不再接收新订单
    for (auto &t: chefs) t.join();

    ready_dishes_q.close(); // 不再有新出菜
    for (auto &t: waiters_serve) t.join();

    std::cout << "=== Restaurant closed gracefully ===\n";
    return 0;
}
