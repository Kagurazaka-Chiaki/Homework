/**
 * @brief 371. 两整数之和
 * 
 * https://leetcode-cn.com/problems/sum-of-two-integers/
 * 
**/

class Solution {

    int add(int a, int b) {
        if (a == 0) { return b; }
        if (b == 0) { return a; }
        unsigned int carry = 0;
        while (b != 0) {
            carry = (a & b);   // 仅 0b1 + 0b1 产生进位 
            a = a ^ b;         // 相加但不计进位
            b = carry << 1;
        }
        return a;
    }

public:
    int getSum(int a, int b) {
        return add(a, b);
    }
};