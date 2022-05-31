/**
 * @brief 2248. 多个数组求交集
 * 
 * https://leetcode-cn.com/problems/intersection-of-multiple-arrays/submissions/
**/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        vector<int> result;
        for(auto arr: nums) {
            for(int i: arr) {
                map[i]++;
                if(map[i] == n) {
                    result.push_back(i);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};


int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    return 0;
}
