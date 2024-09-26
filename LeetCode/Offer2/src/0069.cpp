/**
 * @brief 剑指 Offer II 069. 山峰数组的顶部
 * 
 * https://leetcode-cn.com/problems/B1IidL/
 * 
**/

#include <vector>

using namespace std;

class Solution {
  public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int prev = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[prev]) { break; }
            prev = i;
        }
        return prev;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    return 0;
}