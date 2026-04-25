/**
 * 3408. 设计任务管理器
 * https://leetcode.cn/problems/design-task-manager/
**/

#include <unordered_map>

#include <queue>
#include <vector>

class TaskManager {

    struct data {
        int user_id;
        int task_id;
        int priority;
    };

    // overload < operator for priority_queue
    friend bool operator<(const data &a, const data &b) {
        if (a.priority != b.priority) {
            return a.priority < b.priority; // higher priority first
        }
        return a.task_id > b.task_id; // lower task_id first
    }

    struct user_task {
        int priority;
        int user_id;
    };

    std::unordered_map<int, user_task> map;
    std::priority_queue<data>          pq;

  public:
    TaskManager(std::vector<std::vector<int>> &tasks) {
        for (auto &task: tasks) {
            this->add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        map[taskId] = {priority, userId};
        pq.emplace(userId, taskId, priority);
    }

    void edit(int taskId, int newPriority) {
        this->add(map[taskId].user_id, taskId, newPriority);
    }

    void rmv(int taskId) {
        map[taskId].priority = -1;
    }

    int execTop() {
        while (!pq.empty()) {
            auto &[p, t, u] = pq.top();
            pq.pop();
            if (map[t].priority == p && map[t].user_id == u) {
                rmv(t);
                return u;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

/**
 *
**/


#include <iostream>

auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;
    /* code */
    std::cout << "Hello, 世界! \xF0\x9F\x98\x89 \n"
              << std::endl;
    return 0;
}
