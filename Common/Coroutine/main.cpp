
#include "minicoro.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <coroutine>
#include <memory>
#include <string>


const std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("console");


float total_lerp_time = 10.0f; // 10 seconds

float current_lerp_time = 0.0f;

auto g = minicoro::generator<float>::lerp(0, 10, 0.033f);

// int foo() {
//
//    logger->info("foo() called");
//    co_await std::suspend_always{};
//    logger->info("foo() resumed");
//
//    return 42;
// }

bool g_switch = false;

void on_tick(float delta_time) {
    // logger->info("on_tick() called with delta_time = {}", delta_time);


    current_lerp_time += delta_time;
    if (current_lerp_time >= total_lerp_time) {
        current_lerp_time = total_lerp_time;
    } else {
        if (g.has_next()) {
            logger->info("{}", g.next());
        }
    }
}

minicoro::generator<int> sequence() {
    int i = 0;
    while (i < 5) {
        co_await i++;
    }
}

minicoro::generator<int> fibonacci() {
    co_yield 0; // fib(0)
    co_yield 1; // fib(1)

    int a = 0;
    int b = 1;
    while (true) {
        co_yield a + b; // fib(N), N > 1
        b = a + b;
        a = b - a;
    }
}

float g_color = 0.0f;

// lerp generator by current lerp time
// 0.0f -> 10.0f
// minicoro::generator<float> gen_change_if(bool condition) {
//
//     if (condition) {
//         while (g_color != 1.0f) {
//             g_color =
//             co_yield g_color;
//         }
//     } else {
//         while (g_color != 0.0f) {
//             g_color =
//             co_yield g_color;
//
//         }
//     }
// }


auto eq(float a, float b) -> bool {
    return std::fabs(a - b) <= 0.02f;
}

int main() {

    logger->info("Hello, World!");


    float const delta_time = 0.033f;
    // 60 fps = 0.01667f
    // 30 fps = 0.03333f

    float const total_time = 60.0f;

    // auto g = minicoro::generator<float>::lerp(0, 10, 0.016f);


    float const op_time_1 = 20.0f;

    float const op_time_2 = 40.0f;


    // minicoro::log_to_file("log.csv", g);

    
    for (int i = 0; i < 100; ++i) {
        if (g.has_next()) {
            logger->info("{}", g.next());
        } else {
            break;
        }
    }

    // std::unique_ptr<minicoro::generator<float>> seq = nullptr;

    // float current_time = 0.0f;
    // while (current_time < total_time) {

    //     on_tick(delta_time);


    //     if (eq(current_time, op_time_1)) {
    //         logger->info("operation 1 at time = {}", current_time);
    //         g_switch = true;
    //     }

    //     if (eq(current_time, op_time_2)) {
    //         logger->info("operation 2 at time = {}", current_time);
    //         g_switch = false;
    //     }

    //     // logger->info("current_time = {}", current_time);
    //     current_time += delta_time;
    // }


    // lerp_time::lerp_time<float> this_lerp(0, 10, std::chrono::milliseconds(1000));

    // // auto v = this_lerp.get_current_value();

    // // std::cout << v << std::endl;

    return EXIT_SUCCESS;
}
