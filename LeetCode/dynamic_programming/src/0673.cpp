/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode.cn/problems/number-of-longest-increasing-subsequence/description/
 *
 * 给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
 * 
 * 注意 这个数列必须是 严格 递增的。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 
 * 
 * 示例 2:
 *
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 
 * 提示: 
 * 1 <= nums.length <= 2000
 * -10^6 <= nums[i] <= 10^6
 * 
 * 
 */

#include "dplib/solution.hpp"

#include <iostream>
#include <vector>

auto dp::solution::findNumberOfLIS(std::vector<int> &nums) -> int {

    int n = nums.size();

    auto dp = std::vector<int>(n, 1);
    auto fp = std::vector<int>(n, 1);

    int max = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (fp[i] < fp[j] + 1) {
                    fp[i] = fp[j] + 1;
                    dp[i] = dp[j];
                } else if (fp[i] == fp[j] + 1) {
                    dp[i] += dp[j];
                }
            }
        }
        max = std::max(max, fp[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (fp[i] == max) {
            ans += dp[i];
        }
    }
    return ans;
}

auto main(int, char *argv[]) -> int {
    std::cout << "0673. 最长递增子序列的个数\n";
    std::vector<int> nums = {1, 3, 5, 4, 7};
    std::cout << "Input: [1, 3, 5, 4, 7]\nOutput: " << dp::solution::singleton().findNumberOfLIS(nums) << "\n";
    return 0;
}
