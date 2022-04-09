/**
 * @brief 1572. 矩阵对角线元素的和
 * 
 * https://leetcode-cn.com/problems/matrix-diagonal-sum/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int result = 0;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i == n - j - 1) {
                    result = result + mat[i][j];
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