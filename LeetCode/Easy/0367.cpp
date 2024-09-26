/**
 * @brief 367. 有效的完全平方数
 * 
 * https://leetcode-cn.com/problems/valid-perfect-square/
 * 
**/

#include <cmath>

class Solution {

    int sqrt(int x) {
        if (x == 0) { return 0; }
        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (std::fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }

  public:
    bool isPerfectSquare(int num) {
        int x = (int) sqrt(num);
        return x * x == num;
    }
};