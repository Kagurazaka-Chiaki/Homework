/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Medium (74.25%)
 * Likes:    2567
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.6M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
 * 
 * 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
 * 
 * 返回 你能获得的 最大 利润 。
 * 
 * 示例 1：
 * 
 * 输入：prices = [7,1,5,3,6,4]
 * 输出：7
 * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
 * 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
 * 最大总利润为 4 + 3 = 7 。
 * 
 * 示例 2：
 * 
 * 输入：prices = [1,2,3,4,5]
 * 输出：4
 * 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
 * 最大总利润为 4 。
 * 
 * 示例 3：
 * 
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0。
 * 
 * 提示：
 * 
 * 1 <= prices.length <= 3 * 10^4
 * 0 <= prices[i] <= 10^4
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>

// @lc code=start
class Solution {

    // TODO: 回溯法超时
    void dfs(std::vector<int> const &in_vec, int const p, int const n, int const status, int const val, int &out_res) {
        if (p == n) {
            out_res = std::max(out_res, val);
            return;
        }
        dfs(in_vec, p + 1, n, status, val, out_res);
        switch (status) {
            case 0: // 卖出
            {
                dfs(in_vec, p + 1, n, 1, val - in_vec[p], out_res);
                break;
            }
            case 1: // 持有
            {
                dfs(in_vec, p + 1, n, 0, val + in_vec[p], out_res);
                break;
            }
            default:
                break;
        }
    }


  public:
    int maxProfit(std::vector<int> &prices) {
        int n = prices.size();
        if (n < 2) { return 0; }
        int res = 0;
        dfs(prices, 0, n, 0, 0, res);
        std::cout << "res:" << res << std::endl;
        return res;
    }
};

// @lc code=end
