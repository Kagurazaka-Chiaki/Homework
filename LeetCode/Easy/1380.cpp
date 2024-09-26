/**
 * @brief 1380. 矩阵中的幸运数
 * 
 * https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row_min;
        for (int i = 0; i < m; i++) {
            int temp = INT_MAX;
            for (int j = 0; j < n; j++) {
                temp = min(temp, matrix[i][j]);
            }
            row_min.push_back(temp);
        }

        vector<int> col_max;
        for (int j = 0; j < n; j++) {
            int temp = INT_MIN;
            for (int i = 0; i < m; i++) {
                temp = max(temp, matrix[i][j]);
            }
            col_max.push_back(temp);
        }

        vector<int> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == row_min[i] && matrix[i][j] == col_max[j]) {
                    result.push_back(matrix[i][j]);
                }
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