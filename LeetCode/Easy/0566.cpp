/**
 * @brief 566. 重塑矩阵
 * 
 * https://leetcode-cn.com/problems/reshape-the-matrix/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) { return mat; }
        vector<vector<int>> result(r, vector<int>(c, 0));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                int id = i * c + j;
                result[i][j] = mat[id / n][id % n];
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