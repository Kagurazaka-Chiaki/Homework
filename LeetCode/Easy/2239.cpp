/**
 * @brief 2239. 找到最接近 0 的数字
 * 
 * https://leetcode-cn.com/problems/find-closest-number-to-zero/
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (int i : nums) {
            if (i < 0) {
                a = -min(abs(a), abs(i));
            } else {
                b = min(abs(b), abs(i));
            }
        }
        return abs(a) < b ? a : b;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    return 0;
}
