/**
 * @brief 剑指 Offer 05. 替换空格
 * 
 * https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 * 
**/


#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string replaceSpace(string s) {
        string result = "";
        for (char c : s) {
            if (c == ' ') {
                result += "%20";
            } else {
                result += c;
            }
        }
        return result;
    }
};


std::string replaceSpace(std::string s) {
    int count = 0;
    int length = s.length();

    for (char c : s) {
        if (c == ' ') { count++; }
    }

    int new_length = count * 2 + length;

    s.resize(new_length);

    int j = length;
    for (int i = new_length; i > -1; i--) {
        if (s[j] == ' ') {
            j--;
            s[i--] = '0';
            s[i--] = '2';
            s[i] = '%';
        } else {
            s[i] = s[j--];
        }
    }

    return s;
}

int main(int argc, char const *argv[]) {
    /* code */

    std::cout << replaceSpace("We are happy.") << std::endl;

    return 0;
}

// [17 \0] -> [13 \0]
// [16 \0] -> [12  .]
// [15 \0] -> [11  y]
// [14 \0] -> [10  p]
// [13 \0] -> [ 9  p]
// [12  .] -> [ 8  a]
// [11  y] -> [ 7  h]
// [10  p] -> [ 6   ]
// [ 7  h] -> [ 5  e]
// [ 6   ] -> [ 4  r]
// [ 5  e] -> [ 3  a]
// [ 4  r] -> [ 2   ]
// [ 1  e] -> [ 1  e]
// [ 0  W] -> [ 0  W]
//
// We%20are%20happy.


#include <cstdlib>

#define MAX 10000

char* replaceSpace(char* s){
    char *result = (char *)malloc((3 * MAX + 1) * sizeof(char));
    int return_size = 0;
    for(int i = 0; s[i] != '\0'; ++i) {
        if(s[i] == ' ') {
            result[return_size++] = '%%';
            result[return_size++] = '2';
            result[return_size++] = '0';
        }else {
            result[return_size++] = s[i];
        }
    }
    result[return_size] = '\0';
    return result;
}
