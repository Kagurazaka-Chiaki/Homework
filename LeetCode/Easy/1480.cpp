/**
 * @brief 1480. 一维数组的动态和
 * 
 * https://leetcode-cn.com/problems/running-sum-of-1d-array/
 * 
**/

#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        result.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            result.push_back(nums[i]);
            result[i] = result[i] + result[i - 1];
        }
        return result;
    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
**/
int* runningSum(int* nums, int numsSize, int* returnSize){
    int *result = (int *)malloc(numsSize * sizeof(int));
    result[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        result[i] = nums[i];
        result[i] = result[i] + result[i - 1];
    }
    *returnSize = numsSize;
    return result;
}