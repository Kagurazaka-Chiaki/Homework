class Solution {

    int max(int a, int b) {
        return a > b ? a : b;
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }

    int sign(int x) {
        return x >> 31;
    }

    int add(int a, int b) {
        if (a == 0) { return b; }
        if (b == 0) { return a; }
        unsigned int carry = 0;
        while (b != 0) {
            carry = (a & b);    // 仅 0b1 + 0b1 产生进位 
            a = a ^ b;          // 相加但不计进位
            b = carry << 1;
        }
        return a;
    }

    int negative(int x) {
        return add(~x, 1);
    }

    int abs(int x) {
        return x < 0 ? negative(x) : x;
    }

public:
    int multiply(int A, int B) {
        if (A == 0 || B == 0) { return 0; }
        if (A == 1) { return B; }
        if (B == 1) { return A; }
        int flag = 0;
        if (A < 0) { flag = ~flag; }
        if (B < 0) { flag = ~flag; }
        int result = 0;
        long long a = max(abs(A), abs(B));
        long long b = min(abs(A), abs(B));
        while(b != 0) {
            if((b & 1) != 0) { result = add(result, a); }
            b = b >> 1;         // 加倍
            a = add(a, a);      // 自加
        }
        return flag == 0 ? result : negative(result);
    }
};
