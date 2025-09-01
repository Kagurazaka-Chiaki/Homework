// BM062 斐波那契数列

#include "NowCoderTop101.hpp"

class Solution {
public:
    /**
     *
     * @param n int
     * @return int
     */
    int Fibonacci(int n) {
        // if (n == 1 || n == 2) { return 1; }
        // return Fibonacci(n - 1) + Fibonacci(n - 2);
        if (n < 1) { return 0; }
        if (n == 1 || n == 2) { return 1; }
        int res = 0;
        int a = 0;
        int b = 1;
        for (int i = 2; i < n + 1; ++i) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};