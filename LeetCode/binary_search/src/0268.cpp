

#include "bslib/solution.hpp"

#include <numeric>

// 不用二分
auto bs::solution::missingNumber(std::vector<int> &nums) -> int {
    int n = nums.size();
    int s = std::accumulate(nums.begin(), nums.end(), 0, std::plus<int>());
    int k = ((1 + n) * n) >> 1;
    return k - s;
}