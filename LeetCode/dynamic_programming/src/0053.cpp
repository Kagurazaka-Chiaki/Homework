

#include <dplib/solution.hpp>

// 0053

// int maxSubArray(vector<int>& nums) {
//     int ans = INT_MIN;
//     int c = 0;
//     for (auto const &v : nums) {
//         c += v;
//         if (c > ans) { ans = c; }
//         if (c <= 0) { c = 0; }
//     }
//     return ans;
// }
auto dp::solution::maxSubArray(std::vector<int> &nums) -> int {
    int n = nums.size();
    if (n == 0) { return 0; }
    int res = nums[0];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sum > 0) {
            sum += nums[i];
        } else {
            sum = nums[i];
        }
        res = std::max(res, sum);
    }
    return res;
}
