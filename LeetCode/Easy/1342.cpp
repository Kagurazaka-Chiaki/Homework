/**
 * @brief 1342. 将数字变成 0 的操作次数
 * 
 * https://leetcode-cn.com/problems/number-of-steps-to-reduce-a-number-to-zero/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int numberOfSteps(int num) {
        if (num == 0) { return 0; }
        if (num % 2 == 1) {
            return numberOfSteps(num - 1) + 1;
        } else {
            return numberOfSteps(num / 2) + 1;
        }
    }
};

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    return 0;
}