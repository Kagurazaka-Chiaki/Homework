/**
 * @brief 面试题 16.07. 最大数值
 *
 * https://leetcode-cn.com/problems/maximum-lcci/
 * 
**/

#include <cmath>

class Solution {

    int sign(int x) {
        return (x >> 31) + 1;
    }

public:
    int maximum(int a, int b) {
        return ((long) a + (long) b + abs((long) a - (long) b)) / 2;
    }
};