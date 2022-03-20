
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s1, string s2) {
        return s1.size() != s2.size() ? false : (s1 + s1).find(s2) != -1;
    }
};