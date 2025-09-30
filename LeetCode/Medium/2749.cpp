/**
 * 2749. Minimum Operations to Make the Integer Zero
 * https://leetcode.cn/problems/minimum-operations-to-make-the-integer-zero/
**/

#include <cstdint>
#if __cplusplus >= 202002L
    #include <bit>
#endif

class Solution {

    uint64_t hamming_weight(uint64_t n) {
        n = (n & 0x5555555555555555ULL) + ((n >> 1) & 0x5555555555555555ULL);
        n = (n & 0x3333333333333333ULL) + ((n >> 2) & 0x3333333333333333ULL);
        n = (n & 0x0F0F0F0F0F0F0F0FULL) + ((n >> 4) & 0x0F0F0F0F0F0F0F0FULL);
        n = (n & 0x00FF00FF00FF00FFULL) + ((n >> 8) & 0x00FF00FF00FF00FFULL);
        n = (n & 0x0000FFFF0000FFFFULL) + ((n >> 16) & 0x0000FFFF0000FFFFULL);
        n = (n & 0x00000000FFFFFFFFULL) + ((n >> 32) & 0x00000000FFFFFFFFULL);
        return n;
    }

  public:
    int makeTheIntegerZero(int num1, int num2) {
        for (uint32_t k = 1; k <= (num1 - num2 * k); ++k) {
#if __cplusplus >= 202002L
            if (k >= std::popcount(num1 - num2 * k)) { //
                return k;
            }
#else
            if (k >= hamming_weight(num1 - num2 * k)) {
                return k;
            }
#endif
        }
        return -1;
    }
};
