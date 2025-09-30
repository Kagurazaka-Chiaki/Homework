/**
 * 0042. 接雨水
**/

#include <algorithm>
#include <vector>

class Solution {

    // 前后缀缀数组最大值
    auto f1(std::vector<int>& height) -> int {
        int n = height.size();
        if (n == 0) { return 0; }
        auto lm = std::vector<int>(n, 0);
        lm[0] = height[0];
        for (int i = 1; i < n; ++i) {
            lm[i] = std::max(lm[i - 1], height[i]);
        }
        auto rm = std::vector<int>(n, 0);
        rm[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rm[i] = std::max(rm[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += std::min(lm[i], rm[i]) - height[i];
        }
        return ans;
    }

    // 相向双指针
    auto f2(std::vector<int>& height) -> int {
        int n = height.size();
        if (n == 0) { return 0; }
        int l = 0;
        int r = n - 1;
        int pre_max = 0;
        int suf_max = 0;
        int ans = 0;
        while (l < r) {
            pre_max = std::max(pre_max, height[l]);
            suf_max = std::max(suf_max, height[r]);
            if (pre_max < suf_max) {
                ans += pre_max - height[l];
                l++;
            } else {
                ans += suf_max - height[r];
                r--;
            }
        }
        return ans;
    }



public:
    int trap(std::vector<int>& height) {
        return f2(height);
    }
};