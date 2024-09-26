/**
 * @brief 1929. 数组串联
 * 
 * https://leetcode-cn.com/problems/concatenation-of-array/
 * 
**/

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> getConcatenation(vector<int> &nums) {
        vector<int> result = nums;
        for (int i: nums) {
            result.push_back(i);
        }
        return result;
    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
**/
int *getConcatenation(int *nums, int numsSize, int *returnSize) {
    int *result = (int *) malloc(2 * numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[i + numsSize] = result[i] = nums[i];
    }
    *returnSize = 2 * numsSize;
    return result;
}