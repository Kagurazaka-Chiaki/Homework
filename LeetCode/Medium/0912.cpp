/**
 * @brief 912. 排序数组
 * 
 * https://leetcode-cn.com/problems/sort-an-array/
 * 
**/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};


int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
**/
int* sortArray(int* nums, int numsSize, int* returnSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = numsSize; 
    return nums;
}