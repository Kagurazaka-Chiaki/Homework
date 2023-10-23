


#include "bslib/solution.hpp"



//
auto bs::solution::searchInsert(std::vector<int> &nums, int target) -> int {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int ans = n;
    while (left <= right) {
        int mid = ((right - left) >> 1) + left;
        if (target <= nums[mid]) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
