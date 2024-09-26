/**
 * @brief 1389. 按既定顺序创建目标数组
 * 
 * https://leetcode-cn.com/problems/create-target-array-in-the-given-order/
 * 
**/

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index) {
        vector<int> result;
        for (int i = 0; i < index.size(); i++) {
            result.insert(result.begin() + index[i], nums[i]);
        }
        return result;
    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
**/
int *createTargetArray(int *nums, int numsSize, int *index, int indexSize, int *returnSize) {
    int length = 0;
    int *result = (int *) malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        int idx = index[i];
        int ins = nums[i];
        for (int j = length; j > idx; j--) {
            result[j] = result[j - 1];
        }
        result[idx] = ins;
        ++length;
    }
    *returnSize = length;
    return result;
}