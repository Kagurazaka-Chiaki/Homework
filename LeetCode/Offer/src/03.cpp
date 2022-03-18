/**
 *
**/


#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>


// class Solution {
// public:
//     int findRepeatNumber(std::vector<int> &nums) {

//     }
// };

const int p = 99991; // 100000


int h(int x) {
    return x % p;
}


int findRepeatNumber(std::vector<int> &nums) {
    std::unordered_map<int, bool> map;
    for (int num : nums) {
        if (map[num]) return num;
        map[num] = true;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    /* code */
    (void) argc; (void) argv;
    return 0;
}