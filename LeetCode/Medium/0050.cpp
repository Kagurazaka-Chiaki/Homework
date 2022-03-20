/**
 * @brief 50. Pow(x, n)
 * 
 * https://leetcode-cn.com/problems/powx-n/
 * 
**/

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 || x == 1) { return x; }
        if (n == 0) { return 1; }
        if (n == 1) { return x; }
        long p = n;
        if (n < 0) {
            x = 1 / x;
            p = -p;
        }
        double result = 1.0f;
        while (p != 0) {
            if (p & 1) { 
                result *= x; 
            }
            x *= x;
            p >>= 1;
        }
        return result;
    }
};