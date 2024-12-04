// BM19 寻找峰值

#include "NowCoderTop101.hpp"

#include <vector>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int findPeakElement(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) { return -1; }
        if (n == 1) { return 0; }
        if (n == 2) { return nums[0] > nums[1] ? 0 : 1; }
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = l + ((r - l) / 2);
            if (nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};