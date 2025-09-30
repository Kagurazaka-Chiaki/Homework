/**
 * 1317. Convert Integer to the Sum of Two No-Zero Integers
 * https://leetcode.cn/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
**/

#include <vector>

class Solution {
  public:
    std::vector<int> getNoZeroIntegers(int n) {
        int a    = 0;
        int base = 1;
        for (int x = n; x > 1; x /= 10) {
            int d = x % 10;
            if (d <= 1) {
                d += 10;
                x -= 10;
            }
            a += d / 2 * base;
            base *= 10;
        }
        return {a, n - a};
    }
};
