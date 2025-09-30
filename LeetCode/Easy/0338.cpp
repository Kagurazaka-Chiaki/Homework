
/**
 * 338. Counting Bits
 * https://leetcode.cn/problems/counting-bits/
**/


#include <vector>

class Solution {

    int f4(uint32_t n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
        n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);
        n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF);
        return n;
    }

  public:
    std::vector<int> countBits(int n) {
        std::vector<int> res(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            res[i] = f4(i);
        }
        return res;
    }
};
