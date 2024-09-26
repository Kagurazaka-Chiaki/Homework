#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        int state = 0;
        char current;
        string str;
        cin >> str;
        char last = str[0];
        string ans = "";
        ans = ans + str[0];

        for (int i = 1; i < str.size(); i++) {
            current = str[i];
            switch (state) {
                case 0:
                    if (current == last) {
                        state = 1;
                    } else {
                        state = 0;
                    }
                    break;
                case 1:
                    if (current == last) {
                        continue;
                    } else {
                        state = 2;
                    }
                    break;
                case 2:
                    if (current == last) {
                        continue;
                    } else {
                        state = 0;
                    }
                    break;
                default:
                    break;
            }
            ans = ans + current;
            last = current;
        }
        cout << ans << endl;
    }
    return 0;
}
