/**
 * @brief 326. 3 的幂
 * 
 * https://leetcode-cn.com/problems/power-of-three/
 * 
**/

#include <cmath>

class Solution {

    double log(int a, int b) {
        return std::log(a) / std::log(b);
    }

    bool is_zero(int x) {
        return ~x == -1;
    }

  public:
    bool isPowerOfThree(int n) {
        if (n <= 0) { return false; }
        if (n == 387420489 || n == 1162261467) { return true; }
        if (n > 387420489) { return false; }
        double diff = (log(n, 3) - ceil(log(n, 3))) * 1e9;
        // return is_zero(diff) ? true : false;
        return n > 0 && 1162261467 % n == 0;
    }
};