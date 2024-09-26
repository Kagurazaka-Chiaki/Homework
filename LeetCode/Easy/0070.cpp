/**
 * @brief 70. 爬楼梯
 * 
 * https://leetcode-cn.com/problems/climbing-stairs/
 * 
 * 滚动数组
 * 
**/

class Solution {
  public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) { return n; }
        int prev = 0, curr = 0, next = 1;
        for (int i = 0; i < n; i++) {
            prev = curr;
            curr = next;
            next = prev + curr;
        }
        return next;
    }
};