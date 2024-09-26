/**
 * @brief 561. 数组拆分 I
 * 
 * https://leetcode-cn.com/problems/array-partition-i/
 * 
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int arrayPairSum(vector<int> &nums) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i = i + 2) {
            result = result + nums[i];
        }
        return result;
    }
};