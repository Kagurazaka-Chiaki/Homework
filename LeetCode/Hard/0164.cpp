/**
 * @brief 164. 最大间距
 * 
 * https://leetcode-cn.com/problems/maximum-gap/
 * 
 * 
 * 困难题，要求 O(n), 但先用排序逃课，欸嘿
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maximumGap(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int max_gap = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] > max_gap) {
                max_gap = nums[i] - nums[i - 1];
            }
        }
        return max_gap;
    }
};

// C
int cmp(void const *a, void const *b) {
    return *(int *) a - *(int *) b;
}

int maximumGap(int *nums, int numsSize) {
    int max = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] - nums[i - 1] > max) {
            max = nums[i] - nums[i - 1];
        }
    }
    return max;
}
