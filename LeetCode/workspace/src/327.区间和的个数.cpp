/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 *
 * https://leetcode.cn/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (40.36%)
 * Likes:    590
 * Dislikes: 0
 * Total Accepted:    47.8K
 * Total Submissions: 118.4K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * 给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和
 * upper）之内的 区间和的个数 。
 * 
 * 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-2,5,-1], lower = -2, upper = 2
 * 输出：3
 * 解释：存在三个区间：[0,0]、[2,2] 和 [0,2] ，对应的区间和分别是：-2 、-1 、2 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0], lower = 0, upper = 0
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * -10^5 
 * 题目数据保证答案是一个 32 位 的整数
 * 
 * 
 */


#include <vector>

// @lc code=start
class Solution {

    void build_tree(std::vector<long> &out_tree, int s, int t, int p, std::vector<int> const &in_data) {
        if (s == t) {
            out_tree[p] = in_data[s];
            return;
        }
        int m = (s + t) / 2;
        build_tree(out_tree, s, m, 2 * p, in_data);
        build_tree(out_tree, m + 1, t, 2 * p + 1, in_data);
        out_tree[p] = out_tree[2 * p] + out_tree[2 * p + 1];
    }

    long get_sum(std::vector<long> const &in_tree, int s, int t, int p, int l, int r) {
        if (l <= s && t <= r) {
            return in_tree[p];
        }
        long res = 0;
        int m = s + ((t - s) >> 1);
        if (l <= m) {
            res += get_sum(in_tree, s, m, 2 * p, l, r);
        }
        if (r > m) {
            res += get_sum(in_tree, m + 1, t, 2 * p + 1, l, r);
        }
        return res;
    }

  public:
    int countRangeSum(std::vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        if (n == 1) {
            return lower <= nums[0] && nums[0] >= upper ? 1 : 0;
        }
        auto tree = std::vector<long>(4 * n, 0);
        build_tree(tree, 0, n - 1, 1, nums);
        int total = 0;
        // TODO：超时
        // int a = 0;
        // int b = 0;
        // while(a < n) {
        //     for (b = a; b < n; ++b) {
        //         // printf("(%d, %d)", a , b);
        //         auto s = get_sum(tree, 0, n - 1, 1, a, b);
        //         if (lower <= s && s <= upper) {
        //             total += 1;
        //         }
        //     }
        //     ++a;
        // }
        return total;
    }
};

// @lc code=end
