/**
 * @brief 1672. 最富有客户的资产总量
 * 
 * https://leetcode-cn.com/problems/richest-customer-wealth/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int result = INT_MIN;
        for (int i = 0; i < accounts.size(); i++) {
            int total = 0;
            for (int j: accounts[i]) {
                total = total + j;
            }
            if (total > result) {
                result = total;
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