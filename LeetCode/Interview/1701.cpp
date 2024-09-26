/**
 * @brief ### 面试题 17.01. 不用加号的加法
 * 
 *
 * 
**/

class Solution {
  public:
    int add(int a, int b) {
        if (a == 0) { return b; }
        if (b == 0) { return a; }
        unsigned int carry = 0;
        while (b != 0) {
            carry = (a & b); // 仅 0b1 + 0b1 产生进位
            a = a ^ b;       // 相加但不计进位
            b = carry << 1;
        }
        return a;
    }
};