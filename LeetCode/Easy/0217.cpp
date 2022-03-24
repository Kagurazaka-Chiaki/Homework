/**
 * @brief 217. 存在重复元素
 * 
 * https://leetcode-cn.com/problems/contains-duplicate/
 * 
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) { return true; }
        }
        return false;
    }
};

int cmp(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 1; i < numsSize; ++i) {
        if(nums[i] == nums[i-1]) {
            return true;
        }
    }
    return false;
}