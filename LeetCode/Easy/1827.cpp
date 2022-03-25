/**
 * @brief 1827. 最少操作使数组递增
 * 
 * https://leetcode-cn.com/problems/minimum-operations-to-make-the-array-increasing/
 * 
**/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        int prev = nums[0] + 1;
        for (int i = 1; i < nums.size(); i++) {
            if (prev < nums[i]) {
                prev = nums[i] + 1;
            } else {
                result = result + (prev - nums[i]);
                prev++;
            }
        }
        return result;
    }
};