/**
 * @brief 1920. 基于排列构建数组
 * 
 * https://leetcode-cn.com/problems/build-array-from-permutation/
 * 
**/

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> buildArray(vector<int> &nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(nums[nums[i]]);
        }
        return result;
    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *buildArray(int *nums, int numsSize, int *returnSize) {
    int *result = (int *) malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        result[i] = nums[nums[i]];
    }
    *returnSize = numsSize;
    return result;
}