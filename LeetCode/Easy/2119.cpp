/**
 * @brief 2119. 反转两次的数字
 * 
 * https://leetcode-cn.com/problems/a-number-after-a-double-reversal/
 * 
**/

#include <cstdio>
#include <cstdlib>

class Solution {

    double pow(double x, int n) {
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

    int digit(int x) {
        int count = 1;
        int condition = x / pow(10, count);
        while (condition) {
            condition = condition / 10;
            count++;
        }
        return count;
    }

    int reverse(int num) {
        int compare = num;
        int num_size = digit(compare);
        int *stk = (int *)malloc(num_size * sizeof(int));
        for (int i = 1; i < num_size + 1; i++) {
            int pow_10 = (int) pow(10, (num_size - i));
            int k = compare / pow_10;
            compare = compare - k * pow_10;
            stk[i - 1] = k;
        }
        int reversed = stk[0];
        for (int i = num_size - 1; i > 0; i--) {
            int pow_10 = (int) pow(10, i);
            reversed = reversed + pow_10 * stk[i];
        }
        free(stk);
        return reversed;
    }

public:
    bool isSameAfterReversals(int num) {
        // if (num <  0) { return false; } // 0 <= nums <= 10e6
        // if (num < 10) { return  true; }
        // int result = reverse(reverse(num));
        // return result == num;
        // return (num != 0 && num % 10 == 0) ? false : true;
        return num == 0 || num % 10 != 0;
    }
};