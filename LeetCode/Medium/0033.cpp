/**
 * @brief 33. 搜索旋转排序数组
 * 
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * 
**/

#include <vector>

class Solution {
  public:
    int search(std::vector<int> &nums, int target) {
        int result = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                result = i;
                break;
            }
        }
        return result;
    }
};