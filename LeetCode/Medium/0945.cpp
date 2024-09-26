/**
 * @brief 945. 使数组唯一的最小增量
 * 
 * https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/
 * 
**/

#include <bits/stdc++.h>

using namespace std;

class Solution {

    void display(unordered_map<int, int> hash_map, string str) {
        cout << str << endl;
        for (auto &x: hash_map) {
            cout << x.first << " : " << x.second << endl;
        }
    }

  public:
    int minIncrementForUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int result = 0, taken = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) {
                taken++;
                result -= nums[i];
            } else {
                int give = min(taken, nums[i] - nums[i - 1] - 1);
                result += give * (give + 1) / 2 + give * nums[i - 1];
                taken -= give;
            }
        }
        if (nums.size() > 0) {
            result += taken * (taken + 1) / 2 + taken * nums.back();
        }
        return result;
    }
};