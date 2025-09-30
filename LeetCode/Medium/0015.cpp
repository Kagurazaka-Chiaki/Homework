/**
 * 0015. 3Sum
**/

#include <algorithm>
#include <vector>

class Solution {

    struct tri {
        int a;
        int b;
        int c;

        tri(int x, int y, int z)
            : a(x), b(y), c(z) {}

        auto operator==(tri const &other) const -> bool {
            return (a == other.a && b == other.b && c == other.c) ||
                   (a == other.a && b == other.c && c == other.b) ||
                   (a == other.b && b == other.a && c == other.c) ||
                   (a == other.b && b == other.c && c == other.a) ||
                   (a == other.c && b == other.a && c == other.b) ||
                   (a == other.c && b == other.b && c == other.a);
        }
    };

    struct tri_hash {
        auto operator()(tri const &t) const -> size_t {
            return std::hash<int>()(t.a) ^ std::hash<int>()(t.b) ^ std::hash<int>()(t.c);
        }
    };

  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
        if (nums.size() < 3) { return {}; }
        int n = nums.size();
        if (n == 3) {
            if (nums[0] + nums[1] + nums[2] == 0) {
                return {nums};
            } else {
                return {};
            }
        }
        // std::unordered_set<tri, tri_hash> set;
        // for (int i = 0; i < n; ++i) {
        //     int a = nums[i];
        //     for (int j = 0; j < n; ++j) {
        //         if (j == i) { continue; }
        //         int b = nums[j];
        //         for (int k = 0; k < n; ++k) {
        //             if (k == i || k == j) { continue; }
        //             int c = nums[k];
        //             if (a + b + c == 0) {
        //                 auto t = tri(a, b, c);
        //                 set.insert(t);
        //             }
        //         }
        //     }
        // }
        // std::vector<std::vector<int>> ans;
        // ans.reserve(set.size());
        // for (const auto& t: set) {
        //     ans.push_back({t.a, t.b, t.c});
        // }
        // return ans;
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < n - 2; ++i) {
            int a = nums[i];
            if (i > 0 and a == nums[i - 1]) {
                continue;
            }
            if (a + nums[i + 1] + nums[i + 2] > 0) {
                break;
            }
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int s = a + nums[l] + nums[r];
                if (s > 0) {
                    r--;
                } else if (s < 0) {
                    l++;
                } else {
                    ans.push_back({a, nums[l], nums[r]});
                    do {
                        l++;
                    } while (l < r and nums[l] == nums[l - 1]);
                    do {
                        r--;
                    } while (l < r and nums[r] == nums[r + 1]);
                }
            }
        }
        return ans;
    }
};