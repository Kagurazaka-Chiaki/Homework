/**
 * 1953. Maximum Number of Weeks for Which You Can Work
 * https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/
**/

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    long long numberOfWeeks(std::vector<int> &milestones) {
        long long longest = *std::max_element(milestones.begin(), milestones.end());
        long long rest    = std::accumulate(milestones.begin(), milestones.end(), 0LL) - longest;
        if (longest > rest + 1) {
            return rest * 2 + 1;
        } else {
            return longest + rest;
        }
    }
};
