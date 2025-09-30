/**
 * 0209. Minimum Size Subarray Sum
 * https://leetcode.com/problems/minimum-size-subarray-sum/
**/


#include <vector>

class Solution {
  public:
    int minSubArrayLen(int target, std::vector<int> &nums) {
        int n   = nums.size();
        int ans = n + 1;
        int sum = 0, left = 0;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }
            if (sum >= target) {
                ans = std::min(ans, right - left + 1);
            }
        }
        return ans <= n ? ans : 0;
    }
};