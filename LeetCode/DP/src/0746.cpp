/**
 *
 **/

#include "dplib/solution.hpp"


auto dp::solution::minCostClimbingStairs(std::vector<int> const &cost) -> int {
    auto len = cost.size();
    // dp 数组迭代
    // auto dp = make_unique<int[]>(len + 1);
    // dp[0] = dp[1] = 0;
    // for (auto i = 2; i < len + 1; i++) {
    //     dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    // }
    // return dp[len];
    // 滚动数组
    auto prev = 0, curr = 0, next = 0;
    for (auto i = 2; i < len + 1; i++) {
        next = std::min(curr + cost[i - 1], prev + cost[i - 2]);
        prev = curr;
        curr = next;
    }

    return curr;
}
