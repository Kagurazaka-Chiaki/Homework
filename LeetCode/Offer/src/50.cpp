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
//     char firstUniqChar(std::string s) {
//         std::unordered_map<char, bool> map;

//         for (char c : s) {
//             int i = (int) c % 26;
//             if (map[i] == true) {
//                 return c;
//             }
//             map[i] = c;
//         }

//         return ' ';
//     }
// };


char firstUniqChar(std::string s) {
    std::unordered_map<char, bool> map;

    for (char c : s) {
        map[c] = map.find(c) == map.end();
    }

    for (char c : s) {
        if (map[c]) { return c; }
    }

    return ' ';
}


int main(int argc, char const *argv[]) {
    /* code */
    (void) argc; (void) argv;


    std::string sample = "njdaks";

    char result = firstUniqChar(sample);

    std::cout << " [ " << result << " ] " << std::endl;

    return 0;
}