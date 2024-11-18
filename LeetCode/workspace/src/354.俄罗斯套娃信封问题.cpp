/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 *
 * https://leetcode.cn/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (35.43%)
 * Likes:    1041
 * Dislikes: 0
 * Total Accepted:    119.3K
 * Total Submissions: 336.8K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
 * 
 * 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 * 
 * 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 * 
 * 注意：不允许旋转信封。
 * 
 * 示例 1：
 * 
 * 输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * 输出：3
 * 解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 * 
 * 示例 2：
 * 
 * 输入：envelopes = [[1,1],[1,1],[1,1]]
 * 输出：1
 * 
 * 提示：
 * 
 * 1 <= envelopes.length <= 10^5
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^5
 * 
 */

#include "LeetCode.hpp"

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
  public:
    int maxEnvelopes(std::vector<std::vector<int>> &envelopes) {
        if (envelopes.empty()) { return 0; }
        // [[5,4],[6,4],[6,7],[2,3]]
        std::sort(
            envelopes.begin(), envelopes.end(),
            [](auto const &a, auto const &b) {
                return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
            }
        );
        // [
        // [2, 3],
        // [5, 4],
        // [6, 7],
        // [6, 4]
        // ]
        auto dp = std::vector<int>();
        dp.push_back(envelopes[0][1]);
        for (auto const &envelope : envelopes) {
            if (int num = envelope[1]; num > dp.back()) {
                dp.push_back(num);
            } else {
                auto it = std::lower_bound(dp.begin(), dp.end(), num);
                *it = num;
            }
        }
        return dp.size();

        // TODO: 直接 dp 超时
        // auto dp = std::vector<int>(envelopes.size(), 1);
        // for (int i = 0; i < envelopes.size(); ++i) {
        //     for (int j = 0; j < i; ++j) {
        //         if (envelopes[i][1] > envelopes[j][1]) {
        //             dp[i] = std::max(dp[i], dp[j] + 1);
        //         }
        //     }
        // }
        // auto ans = std::max_element(dp.begin(), dp.end());
        // return *ans;
    }
};

// @lc code=end
