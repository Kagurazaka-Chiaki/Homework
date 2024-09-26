/**
 * @brief 1582. 二进制矩阵中的特殊位置
 * 
 * https://leetcode-cn.com/problems/special-positions-in-a-binary-matrix/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {

    int check(vector<vector<int>> &mat, int row, int col) {
        int rows = mat.size();
        int cols = mat[0].size();
        if (mat[row][col] != 1) { return 0; }
        for (int i = 0; i < rows; i++) {
            if (i != row && mat[i][col]) {
                return 0;
            }
        }
        for (int i = 0; i < cols; i++) {
            if (i != col && mat[row][i]) {
                return 0;
            }
        }
        return 1;
    }

  public:
    int numSpecial(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int result = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result += check(mat, i, j);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    return 0;
}