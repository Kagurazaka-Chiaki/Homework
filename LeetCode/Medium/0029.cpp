/**
 * @brief 
 * 
 * 
 * 
**/

#include <climits>

class Solution {

    long multiply(long a, long b) {
        long ans = 0;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans += a;
            }
            b >>= 1;
            a += a;
        }
        return ans;
    }


  public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) { return 0; }
        if (divisor == 1) { return dividend; }
        if (divisor == 2) { return dividend >> 1; }
        if (divisor == -1) {
            return (dividend > INT_MIN) ? -dividend : INT_MAX;
        }

        int flag = 0;
        long x = dividend, y = divisor;
        if (x < 0) {
            flag = ~flag;
            x = -x;
        }
        if (y < 0) {
            flag = ~flag;
            y = -y;
        }
        // left = quotient = 0
        long quotient = 0;
        long right = x;
        while (quotient < right) {
            long mid = (quotient + right + 1) >> 1;
            if (multiply(mid, y) <= x) {
                quotient = mid;
            } else {
                right = mid - 1;
            }
        }
        return flag == 0 ? quotient : -quotient;
    }
};