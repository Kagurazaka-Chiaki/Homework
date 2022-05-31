#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GrayCode {
public:
    vector<string> getGray(int n) {
        // write code here
        vector<string> gray;

        if (n == 1) {
            gray.push_back("0");
            gray.push_back("1");
            return gray;
        }

        vector<string> last_gray = getGray(n - 1);
        for (int i = 0; i < last_gray.size(); i++) {
            gray.push_back("0" + last_gray[i]);
        }
        for (int i = last_gray.size() - 1; i >= 0; i--) {
            gray.push_back("1" + last_gray[i]);
        }

        return gray;
    }
};