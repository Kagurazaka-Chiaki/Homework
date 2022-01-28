/**
 *
**/


#include <iostream>
#include <stack>
#include <vector>
#include <string>


// class Solution {
// public:
//     std::string reverseLeftWords(std::string s, int n) {
//
//     }
// };


void swap_char(std::string &s, int a, int b) {
    s.insert(a, s.substr(b, 1));
    s.insert(b + 1, s.substr(a + 1, 1));
    s.erase(a + 1, 1);
    s.erase(b + 1, 1);
}

void reverse(std::string &s, int a, int b) {
    while (a < b) {
        swap_char(s, a, b);
        a++;
        b--;
    }

}

std::string reverseLeftWords(std::string s, int n) {
    reverse(s, 0, n - 1);
    reverse(s, n, s.size() - 1);
    reverse(s, 0, s.size() - 1);
    return s;
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