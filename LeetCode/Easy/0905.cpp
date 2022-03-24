/**
 * @brief 905. 按奇偶排序数组
 * 
 * https://leetcode-cn.com/problems/sort-array-by-parity/
 * 
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {

    static int parity(int x) {
        return x & 1;
    }

    static bool cmp(int a, int b) {
        return parity(a) - parity(b) < 0 ? true: false;
    }

public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for(int i : nums) {
            result.push_back(i);
        }
        sort(result.begin(), result.end(), cmp);
        return result;
    }
};




int parity(int x) {
    return x & 1;
}

int cmp(const void *a, const void *b) {
    return parity(*(int *)a) - parity(*(int *)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
**/
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; ++i) {
        result[i] = nums[i];
    }
    qsort(result, numsSize, sizeof(int), cmp);
    *returnSize = numsSize;
    return result;
}