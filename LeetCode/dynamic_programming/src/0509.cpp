/**
 *
 **/


#include "dplib/solution.hpp"

int recursion(std::vector<int> &note, int n) {
    if (n == 1 || n == 2) { return 1; }
    if (note[n] != 0) { return note[n]; } // 剪枝
    note[n] = recursion(note, n - 1) + recursion(note, n - 2);
    return note[n];
}

int dp::solution::fib(int n) {
    // 递归
    // if (n == 1 || n == 2) {
    //     return 1;
    // } else {
    //     return fib(n - 1) + fib(n - 2);
    // }
    // 备忘录递归
    // if (n < 1) { return 0; }
    // std::vector<int> note(n + 1, 0);
    // note.clear();
    // return recursion(note, n);
    // dp 数组迭代
    // std::vector<int> dp(n + 1, 0);
    // dp[1] = dp[2] = 1;
    // for (int i = 3; i <= n; i++) {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // return dp[n];
    // dp 值迭代
    if (n == 1 || n == 2) { return 1; }
    int prev = 1, curr = 1;
    for (int i = 3; i <= n; i++) {
        int result = prev + curr;
        prev = curr;
        curr = result;
    }
    return curr;
}