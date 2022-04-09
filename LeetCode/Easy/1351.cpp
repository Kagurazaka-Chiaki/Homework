/**
 * @brief 1351. 统计有序矩阵中的负数
 * 
 * https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix/
 * 
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for (auto rows : grid) {
            for (auto i : rows) {
                if (i < 0) {
                    result++;
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    return 0;
}