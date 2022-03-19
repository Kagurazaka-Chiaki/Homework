/**
 * @brief 69. x 的平方根 
 * 
 * https://leetcode-cn.com/problems/sqrtx/
 * 
**/


int mySqrt(int x){
    long long i = 0;
    while(true) {
        if ((i * i <= x) && ((i + 1) * (i + 1) > x)) {
            return (int) i;
        }
        i++;
    }
}