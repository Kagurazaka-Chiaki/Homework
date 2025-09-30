/**
 * 191. Number of 1 Bits
 * https://leetcode.cn/problems/number-of-1-bits/
**/


#include <cstdint>

class Solution {

    int f1(uint32_t n) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans += ((n >> i) & 1);
        }
        return ans;
    }

    int f2(uint32_t n) {
        int ans = 0;
        while (n != 0) {
            ans += 1;
            n &= (n - 1);
        }
        return ans;
    }

    uint32_t lowbit(uint32_t x) {
        return x & -x;
    }

    uint32_t highbit(uint32_t x) {
        if (x == 0) { return 0; }
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        return x - (x >> 1);
    }

    int f3(uint32_t n) {
        int ans = 0;
        for (uint32_t i = n; i != 0; i -= lowbit(i)) {
            ans++;
        }
        return ans;
    }

    int f4(uint32_t n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
        n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);
        n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF);
        return n;
    }

  public:
    int hammingWeight(uint32_t n) {
        return f4(n);
    }
};
