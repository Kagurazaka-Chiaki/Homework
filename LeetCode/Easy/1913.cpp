/**
 * @brief 1913. 两个数对之间的最大乘积差
 * 
 * https://leetcode-cn.com/problems/maximum-product-difference-between-two-pairs/
 * 
**/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
    }
};