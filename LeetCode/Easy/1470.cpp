/**
 * @brief 1470. 重新排列数组
 * 
 * https://leetcode-cn.com/problems/shuffle-the-array/
 * 
**/

#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        int i = 0, j = n;
        for (i = 0; i < n; i++) {
            result.push_back(nums[i]);
            result.push_back(nums[j]);
            j++;
        }
        return result;
    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
**/
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int *result = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (i & 1) {
            result[i] = nums[n + (i / 2)];
        } else {
            result[i] = nums[(i + 1) / 2];
        }
    }
    *returnSize = numsSize;
    return result;
}