
#ifndef DP_SOLUTION_HPP
#define DP_SOLUTION_HPP

#include <string>
#include <vector>

namespace dp {
    class solution {
      private:
        solution() = default;

      public:
        // 静态变量 单例模式
        static solution &singleton() noexcept {
            static solution instance;
            return instance;
        }

        // move constructor
        solution(solution &&other) noexcept = delete;

        // move assignment
        auto operator=(solution &&other) noexcept -> solution & = delete;

        // copy constructor
        solution(solution const &other) noexcept = delete;

        // copy assignment
        auto operator=(solution const &other) noexcept -> solution & = delete;

        virtual ~solution() noexcept = default;

        // 0509. 斐波那契数
        auto fib(int n) -> int;

        // 1137. 第 N 个泰波那契数
        auto tribonacci(int n) -> int;

        // 0070. 爬楼梯
        auto climbStairs(int n) -> int;

        // 0746. 使用最小花费爬楼梯
        auto minCostClimbingStairs(std::vector<int> const &cost) -> int;

        // 0198. 打家劫舍
        auto rob(std::vector<int> const &nums) -> int;

        // 0213. 打家劫舍 II

        // 0740. 删除并获得点数

        // 0055. 跳跃游戏

        // 0045. 跳跃游戏 II

        // 0053. 最大子数组和
        auto maxSubArray(std::vector<int> &nums) -> int;

        // 0918. 环形子数组的最大和

        // 0152. 乘积最大子数组

        // 1567. 乘积为正数的最长子数组长度

        // 1014. 最佳观光组合

        // 0121. 买卖股票的最佳时机
        auto maxProfit(std::vector<int> &prices) -> int;

        // 0122. 买卖股票的最佳时机 II

        // 0309. 最佳买卖股票时机含冷冻期

        // 0714. 买卖股票的最佳时机含手续费

        // 0139. 单词拆分

        // 0042. 接雨水

        // 0413. 等差数列划分

        // 0091. 解码方法

        // 0264. 丑数 II

        // 0096. 不同的二叉搜索树

        // 0118. 杨辉三角

        // 0119. 杨辉三角 II

        // 0931. 下降路径最小和

        // 0120. 三角形最小路径和

        // 1314. 矩阵区域和

        // 0304. 二维区域和检索 - 矩阵不可变

        // 0062. 不同路径

        // 0063. 不同路径 II

        // 0064. 最小路径和
        auto minPathSum(std::vector<std::vector<int>> const &grid) -> int;

        // 0221. 最大正方形

        // 0005. 最长回文子串

        // 0516. 最长回文子序列

        // 0300. 最长递增子序列
        auto lengthOfLIS(std::vector<int> &nums) -> int;

        // 0673. 最长递增子序列的个数
        auto findNumberOfLIS(std::vector<int> &nums) -> int;

        // 0646. 最长数对链
        auto findLongestChain(std::vector<std::vector<int>>& pairs) -> int;

        // 0376. 摆动序列

        // 0392. 判断子序列
        auto isSubsequence(std::string s, std::string t) -> bool;

        // 1143. 最长公共子序列
        auto longestCommonSubsequence(std::string text1, std::string text2) -> int;

        // 0072. 编辑距离

        // 0322. 零钱兑换
        auto coinChange(std::vector<int> const &coins, int amount) -> int;

        // 0518. 零钱兑换 II

        // 0377. 组合总和 Ⅳ

        // 0343. 整数拆分

        // 0279. 完全平方数

        // 0338.
        auto countBits(int n) -> std::vector<int>;
    };
} // namespace dp

#endif // DP_SOLUTION_HPP
