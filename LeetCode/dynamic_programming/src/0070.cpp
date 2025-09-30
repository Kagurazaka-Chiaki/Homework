/**
 *  70. Climbing Stairs
**/


#include "dplib/solution.hpp"

#include <coroutine>
#include <generator>
#include <ranges>

std::generator<long long> fib() {
    long long a = 0, b = 1;
    while (true) {
        co_yield std::exchange(a, std::exchange(b, a + b));
    }
}

auto dp::solution::climbStairs(int n) -> int {
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }
    // n = 0 -> f(n) = 0
    // n = 1 -> f(n) = 1
    // n = 2
    // f(n) = f(n - 1) + f(n - 2);
    // int f_n_0 = 1;
    // int f_n_1 = 0;
    // int f_n_2 = 0;
    // for (int i = 0; i < n + 1; ++i) {
    //     f_n_2 = f_n_1 + f_n_0;
    //     f_n_0 = f_n_1;
    //     f_n_1 = f_n_2;
    // }
    // return f_n_2;
    int ans = 0;
    for (auto x: ::fib() | std::views::take(n + 2)) {
        ans = x;
    }
    return ans;
}