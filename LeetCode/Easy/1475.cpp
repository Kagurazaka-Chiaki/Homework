/**
 * @brief 1475. 商品折扣后的最终价格
 * 
 * https://leetcode-cn.com/problems/final-prices-with-a-special-discount-in-a-shop/
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> finalPrices(vector<int> &prices) {
        int length = prices.size();
        vector<int> result(length, 0);
        for (int i = 0; i < length; i++) {
            int j = i + 1;
            while (j < length) {
                if (prices[j] <= prices[i]) {
                    break;
                }
                j++;
            }
            // printf("[%d, %d, %d]\n", j, prices[i], prices[j]);
            if (j == length) {
                result[i] = prices[i];
            } else {
                result[i] = prices[i] - prices[j];
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
