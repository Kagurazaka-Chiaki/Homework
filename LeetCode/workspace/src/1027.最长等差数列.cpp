/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 *
 * https://leetcode.cn/problems/longest-arithmetic-subsequence/description/
 *
 * algorithms
 * Medium (49.92%)
 * Likes:    376
 * Dislikes: 0
 * Total Accepted:    50.6K
 * Total Submissions: 101.3K
 * Testcase Example:  '[3,6,9,12]'
 *
 * 给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。
 * 
 * 回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <= i1 < i2 < ...
 * < ik <= nums.length - 1。并且如果 seq[i+1] - seq[i]( 0 <= i < seq.length - 1)
 * 的值都相同，那么序列 seq 是等差的。
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,6,9,12]
 * 输出：4
 * 解释： 
 * 整个数组是公差为 3 的等差数列。
 * 
 * 示例 2：
 * 
 * 输入：nums = [9,4,7,2,10]
 * 输出：3
 * 解释：
 * 最长的等差子序列是 [4,7,10]。
 * 
 * 示例 3：
 * 
 * 输入：nums = [20,1,15,3,10,5,8]
 * 输出：4
 * 解释：
 * 最长的等差子序列是 [20,15,10,5]。
 * 
 * 提示：
 * 
 * 2 <= nums.length <= 1000
 * 0 <= nums[i] <= 500
 * 
 */

#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
  public:
    int longestArithSeqLength(std::vector<int> &nums) {
        int n = nums.size();
        if (n == 2) {
            return 2;
        }
        if (n == 3) {
            int d1 = nums[1] - nums[0];
            int d2 = nums[2] - nums[1];
            int d3 = nums[2] - nums[0];
            if (d1 == d2) {
                return 3;
            }
            return 2;
        }
        auto s = std::unordered_set<int>();
        for (int k = 1; k < n; ++k) {
            int a = 0;
            int b = k;
            while (b < n) {
                int d = nums[b] - nums[a];
                if (s.find(d) == s.end()) {
                    s.insert(d);
                }
                a++;
                b++;
            }
        }
        auto ans = 0;
        for (auto const& diff : s) {
            auto mp = std::unordered_map<int, int>();
            int k = 0;
            for (auto const& v : nums) {
                mp[v] = mp[v - diff] + 1;
                k = std::max(k, mp[v]);
            }
            ans = std::max(ans, k);
        }
        return ans;
    }
};

// -> ERROR: Time Out
// [0, 250, 500] = 3
// int n = nums.size();
// auto s = std::unordered_set<int>();
// for (int k = 1; k < n; ++k) {
//     int a = 0;
//     int b = k;
//     while (b < n) {
//         int d = nums[b] - nums[a];
//         s.insert(d);
//         a++;
//         b++;
//     }
// }
// auto p = std::vector<int>();
// for (auto const &diff: s) {
//     auto mp = std::unordered_map<int, int>();
//     int k = 0;
//     for (auto const &v: nums) {
//         mp[v] = mp[v - diff] + 1;
//         k = std::max(k, mp[v]);
//     }
//     p.push_back(k);
// }
// auto ans = std::max_element(p.begin(), p.end());
// return *ans;

// -> ERROR: Wrong Answer
// [75,12,29,77,29,84,63,44,79,59,10] => 3
// int n = nums.size();
// int a = 0;
// int b = 1;
// auto l = std::vector<int>();
// while (b < n) {
//     int d = nums[b] - nums[a];
//     auto mp = std::unordered_map<int, int>();
//     int k = 0;
//     for (auto const &v : nums) {
//         mp[v] = mp[v - d] + 1;
//         k = std::max(k, mp[v]);
//     }
//     l.push_back(k);
//     a++;
//     b++;
// }
// auto ans = std::max_element(l.begin(), l.end());
// return *ans;

// -> ERROR: Time Out
// int n = nums.size();
// auto p = std::vector<int>();
// for (int k = 1; k < n; ++k) {
//     int a = 0;
//     int b = k;
//     while (b < n) {
//         int d = nums[b] - nums[a];
//         auto mp = std::unordered_map<int, int>();
//         int q = 0;
//         for (auto const &v : nums) {
//             mp[v] = mp[v - d] + 1;
//             q = std::max(q, mp[v]);
//         }
//         p.push_back(q);
//         a++;
//         b++;
//     }
// }
// auto ans = std::max_element(p.begin(), p.end());
// return *ans;

// @lc code=end
