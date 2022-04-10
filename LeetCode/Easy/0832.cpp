/**
 * @brief 832. 翻转图像
 *
 * https://leetcode-cn.com/problems/flipping-an-image/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = 1 - image[i][n - 1 - j];
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