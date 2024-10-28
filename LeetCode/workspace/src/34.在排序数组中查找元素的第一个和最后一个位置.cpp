/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (44.12%)
 * Likes:    2809
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.5M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 * 
 * 
 */


#include <vector>

// @lc code=start
class Solution {
    int binary_search_left(std::vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int m = l + ((r - l) / 2);
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l] != target ? -1 : l;
    }

    int binary_search_right(std::vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int m = r - ((r - l) / 2);
            if (nums[m] <= target) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return nums[r] != target ? -1 : r;
    }

public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) { return {-1, -1}; }
        int a = binary_search_left(nums, target);
        int b = binary_search_right(nums, target);
        return {a, b};
    }
};
// @lc code=end

