/**
 *
**/

#include "dplib/solution.hpp"


// 打家劫舍
auto dp::solution::rob(std::vector<int> const &nums) -> int {
    if (nums.empty()) { return 0; }
    if (nums.size() == 1) { return nums[0]; }
    int n = nums.size();
    std::vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[n - 1];
}
