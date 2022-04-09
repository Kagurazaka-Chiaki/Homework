/**
 * @brief 766. 托普利茨矩阵
 * 
 * https://leetcode-cn.com/problems/toeplitz-matrix/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check_same(vector<vector<int>>& matrix, int row, int col) {
        int m = matrix.size();
        int n = matrix[0].size();
        int step = 0;
        while(1) {
            if(row + step >= m) { break; }
            if(col + step >= n) { break; }
            if(matrix[row + step][col + step] != matrix[row][col]) { return false; }
            ++step;
        }
        return true;
    }

public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; ++i) {
            if( !check_same(matrix, i, 0) ) {
                return false;
            }    
        }
        for(int i = 0; i < n; ++i) {
            if( !check_same(matrix, 0, i) ) {
                return false;  
            }        
        }
        return true;
    }
};


int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    return 0;
}