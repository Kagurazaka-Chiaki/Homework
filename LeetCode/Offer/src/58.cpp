/**
 * @brief 剑指 Offer 58 - II. 左旋转字符串
 * 
 * https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 *
**/

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

// class Solution {
// public:
//     std::string reverseLeftWords(std::string s, int n) {
//
//     }
// };


void swap_char(string &s, int a, int b) {
    s.insert(a, s.substr(b, 1));
    s.insert(b + 1, s.substr(a + 1, 1));
    s.erase(a + 1, 1);
    s.erase(b + 1, 1);
}

void reverse(string &s, int a, int b) {
    while (a < b) {
        swap_char(s, a, b);
        a++;
        b--;
    }

}

string reverseLeftWords(string s, int n) {
    reverse(s, 0, n - 1);
    reverse(s, n, s.size() - 1);
    reverse(s, 0, s.size() - 1);
    return s;
}


char* reverseLeftWords(char* s, int k) {
    int n = strlen(s);
    char *result = (char *)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        result[i] = s[(i + k) % n];
    }
    result[n] = '\0';
    return result;
}

int main(int argc, char const *argv[]) {
    /* code */
    (void) argc; (void) argv;

    std::string s = "student";
    std::string str = "abcdefg";

    // s.insert(a, s.substr(b, 1));
    // s.insert(b + 1, s.substr(a + 1, 1));
    // s.erase(a + 1, 1);
    // s.erase(b + 1, 1);

    reverse(s, 0, 6);
    std::cout << s.size() << s.length() << std::endl;
    std::string result = reverseLeftWords(str, 2);
    std::cout << result << std::endl;

    return 0;
}