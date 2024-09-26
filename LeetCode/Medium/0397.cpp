/**
 * @brief 397. 整数替换
 * 
 * https://leetcode-cn.com/problems/integer-replacement/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        }
        return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    }
};

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    return 0;
}