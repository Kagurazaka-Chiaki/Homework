/**
 * @brief 169. 多数元素
 * 
 * https://leetcode-cn.com/problems/majority-element/
 * 
**/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};

int cmp(void const *a, void const *b) {
    return (*(int *) a) - (*(int *) b);
}

int majorityElement(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize / 2];
}