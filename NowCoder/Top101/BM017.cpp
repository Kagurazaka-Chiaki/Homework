// BM17 二分查找-I


#include "NowCoderTop101.hpp"

#include <vector>

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(std::vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) { return -1; }
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = l + ((r - l) / 2);
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l] == target ? l : -1;
    }
};