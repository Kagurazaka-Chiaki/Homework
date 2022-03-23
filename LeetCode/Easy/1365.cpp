/**
 * @brief 1365. 有多少小于当前数字的数字
 * 
 * https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 * 
**/

#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
**/
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *result = (int *)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; ++i) {
        result[i] = 0;
        for(int j = 0; j < numsSize; ++j) {   
            if(nums[j] < nums[i]) {
                ++result[i];
            }
        }
    }
    *returnSize = numsSize;
    return result;
}
