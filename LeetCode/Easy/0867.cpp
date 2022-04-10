/**
 * @brief 867. 转置矩阵
 *
 * https://leetcode-cn.com/problems/transpose-matrix/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> result(cols, vector<int>(rows, 0));
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                result[i][j] = matrix[j][i];
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