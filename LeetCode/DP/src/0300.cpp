/**
 *
**/


#include "dplib/solution.hpp"


/**
    300. 最长递增子序列
    [10, 9, 2, 5, 3, 7, 101, 18]
    [2, 3, 7, 101] -> 4
    f(n) = max(f(i)) + 1; i < n & a[i] < a[n]

    T: O(n^2)
    S: O(n)
**/
auto dp::solution::lengthOfLIS(std::vector<int> &nums) -> int {
    int n = nums.size();
    if (n == 0) { return 0; }
    auto dp = std::vector<int>(n, 0);
    for (auto i = 0; i < n; ++i) {
        dp[i] = 1;
        for (auto j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    auto ans = std::max_element(dp.begin(), dp.end());
    return *ans;
}
