/**
 * @brief 153. 寻找旋转排序数组中的最小值
 * 
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
 * 
**/

#include <vector>

class Solution {
  public:
    int findMin(std::vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int pivot = left + (right - left) / 2;
            if (nums[pivot] < nums[right]) {
                right = pivot;
            } else {
                left = pivot + 1;
            }
        }
        return nums[left];
    }
};