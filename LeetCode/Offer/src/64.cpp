/**
 * @brief 剑指 Offer 64. 求 1 + 2 + ... + n
 * 
 * https://leetcode-cn.com/problems/qiu-12n-lcof/
 * 
 * 函数指针
 * 
**/

#include <bits/stdc++.h>

using namespace std;

typedef int (* fun)(int);

int teminator(int n) {
    return 0;
}

int sumNums(int n){
    static fun f[2] = {teminator, sumNums};
    return n + f[!!n](n - 1);
}

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    return 0;
}