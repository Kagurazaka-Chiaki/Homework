/**
 * @brief 2016. 增量元素之间的最大差值
 * 
 * https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements/
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = 0;
        int minimum = INT_MAX;
        for (int i : nums) {
            result = max(result, i - minimum);
            minimum = min(minimum, i);
        }
        return result > 0 ? result : -1;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    return 0;
}
