#include <iostream>

using namespace std;

int const MAX_LENGTH = 50000;

template<typename T>
inline int MAX(T const &a, T const &b) {
    return (a > b ? a : b);
}

int WindowSolve(char str[], int n, int m) {
    int result = INT32_MIN;
    int left = 0, right = 0;
    int an = 0, bn = 0;
    while (right < n) {
        if (str[right] == 'a') {
            an++;
        } else {
            bn++;
        }
        if (an > m && bn > m) {
            result = MAX(result, right - left);
            if (str[left] == 'a') {
                an--;
            } else {
                bn--;
            }
            left++;
        }
        right++;
    }

    result = MAX(result, right - left);
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    char c[MAX_LENGTH + 1] = {'\0'};
    cin >> c;
    cout << WindowSolve(c, n, m) << endl;
    return 0;
}