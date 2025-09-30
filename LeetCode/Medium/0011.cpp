/**
 * 0011. 盛最多水的容器
**/

#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxArea(std::vector<int> &height) {
        int n   = height.size();
        int l   = 0;
        int r   = n - 1;
        int ans = 0;
        while (l < r) {
            int h = std::min(height[l], height[r]);
            int d = r - l;
            ans   = std::max(ans, h * d);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};