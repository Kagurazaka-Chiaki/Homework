/**
 * @brief LCP 06. 拿硬币
 * 
 * https://leetcode-cn.com/problems/na-ying-bi/
 * 
**/

#include <vector>

using namespace std;

class Solution {
public:
    int minCount(vector<int>& coins) {
        int total = 0;
        for (int i : coins) {
            total = total + (i + 1) / 2;
        }
        return total;
    }
};