/**
 * 1304. Find N Unique Integers Sum up to Zero
 * https://leetcode.cn/problems/find-n-unique-integers-sum-up-to-zero
**/

#include <numeric>
#include <vector>

class Solution {
  public:
    std::vector<int> sumZero(int n) {
        std::vector<int> a(n, 0);
        // for (int i = 0; i < n / 2; ++i) {
        //     a[i] = i + 1;
        //     a[i + (n / 2)] = -i - 1;
        // }
        if (n % 2 == 0) {
            std::iota(a.begin(), a.end(), 0);
            a[0] = -((1 + (n - 1)) * (n - 1)) / 2;
        } else {
            std::iota(a.begin(), a.end(), -(n / 2));
        }
        return a;
    }
};
