/**
 * @brief 231. 2 的幂
 * 
 * https://leetcode-cn.com/problems/power-of-two/
 * 
**/

#include <cmath>

class Solution {

    double log(int a, int b) {
        return std::log(a) / std::log(b);
    }

public:
    bool isPowerOfTwo(int n) {
        // if (n <= 0) { return false; }
        // if (n == 536870912 || n == 1073741824) { return true; }
        // return log(n, 2) - (ceil(log(n, 2))) == 0 ? true : false;
        // return n > 0 && (n & (n - 1)) == 0;
        // return n > 0 && (n & -n) == n;
        return n > 0 && 1073741824 % n == 0;
    }

};