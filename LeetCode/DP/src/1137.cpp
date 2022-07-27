/**
 *
**/

#include "Solution.hpp"

#include <iostream>
#include <algorithm>
#include <vector>


// dp 值迭代
int Solution::tribonacci(int n) {
    if (n == 0) { return 0; }
    if (n == 1 || n == 2) { return 1; }
    int a_0 = 0, a_1 = 1, a_2 = 1;
    for (int i = 2; i < n; i++) {
        int temp = a_0 + a_1 + a_2;
        a_0 = a_1;
        a_1 = a_2;
        a_2 = temp;
    }
    return a_2;
}


int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;

    Solution S;
    printf("%d\n", S.tribonacci(4));
    printf("%d\n", S.tribonacci(25));

    return 0;
}