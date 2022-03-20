class Solution {

    void swap(int *a, int *b) {
        *a = (*a) ^ (*b);
        *b = (*a) ^ (*b);
        *a = (*a) ^ (*b);
    }

public:
    // << 1 在 16 行报错 runtime error: left shift of negative value -2147483648
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
};