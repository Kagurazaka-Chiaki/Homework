/**
 *
**/

#include "dplib/solution.hpp"

// 打家劫舍
auto dp::solution::rob(std::vector<int> const &nums) -> int {
    int n = nums.size();
    if (n == 0) { return 0; }
    if (n == 1) { return nums[0]; }
    if (n == 2) { return std::max(nums[0], nums[1]); }
    if (n == 3) { return std::max(nums[0] + nums[2], nums[1]); }
    if (n == 4) {
        int f0 = nums[0];
        int f1 = std::max(nums[0], nums[1]);
        int f2 = std::max(f0 + nums[2], f1);
        int f3 = std::max(f1 + nums[3], f2);
        return f3;
    }
    int f0 = nums[0];
    int f1 = std::max(nums[0], nums[1]);
    int f2 = 0;
    for (int i = 2; i < n; ++i) {
        f2 = std::max(f0 + nums[i], f1);
        f0 = f1;
        f1 = f2;
    }
    // auto dp = std::vector<int>(n, 0);
    // dp[0] = nums[0];
    // dp[1] = std::max(nums[0], nums[1]);
    // for (int i = 2; i < n; ++i) {
    //     dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    // }
    // return dp[n - 1];
    return f2;
}
