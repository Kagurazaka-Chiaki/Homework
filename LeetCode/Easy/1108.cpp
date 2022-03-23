/**
 * @brief 1108. IP 地址无效化
 * 
 * https://leetcode-cn.com/problems/defanging-an-ip-address/
 * 
**/

#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for (char i : address) {
            if (i == '.') {
                result.push_back('[');
                result.push_back('.');
                result.push_back(']');
            } else {
                result.push_back(i);
            }
        }
        return result;
    }

    string defangIPaddr(string address) {
        string result = "";
        for (char c : address) {
            if (c == '.') {
                result += "[.]";
            } else {
                result += c;
            }
        }
        return result;
    }
};

char * defangIPaddr(char * address){
    char *result = (char *)malloc((16 + 6) * sizeof(char));
    int returnSize = 0;
    for(int i = 0; address[i] != '\0'; i++) {
        if(address[i] == '.') {
            result[returnSize++] = '[';
            result[returnSize++] = '.';
            result[returnSize++] = ']';
        }else {
            result[returnSize++] = address[i];
        }
    }
    result[returnSize] = '\0';
    return result;
}