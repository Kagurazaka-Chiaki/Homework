/**
 * @brief 2022. 将一维数组转变成二维数组
 * 
 * https://leetcode-cn.com/problems/convert-1d-array-into-2d-array/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
        int ori = original.size();
        vector<vector<int>> result;
        if (ori != m * n) { return result; }
        result = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = original[i * n + j];
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