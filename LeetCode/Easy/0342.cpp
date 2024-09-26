/**
 * @brief 342. 4的幂
 * 
 * https://leetcode-cn.com/problems/power-of-four/
 * 
**/

class Solution {
  public:
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0) && (n % 3 == 1);
    }
};