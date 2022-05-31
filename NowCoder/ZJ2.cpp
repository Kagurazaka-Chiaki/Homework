#include <stdio.h>
#include <iostream>

using namespace std;

string isDrawGame(long long n, long long k, long long d1, long long d2) {
    if (n % 3 != 0 || (n - k < d1 + d2)) {
        return "no";
    }
    long long a, b, c = 0;
    for (int i = -1; i <= 1; i = i + 2) {
        for (int j = -1; j <= 1; j = j + 2) {
            long long d_1 = d1 * i;
            long long d_2 = d2 * j;
            a = (k - 2 * d_1 + d_2) / 3;
            b = (k + d_1 + d_2) / 3;
            c = (k + d_1 - 2 * d_2) / 3;
            if (a + b + c != k || a < 0 || b < 0 || c < 0) {
                continue;
            }
            if (a > n / 3 || b > n / 3 || c > n / 3) {
                continue;
            }
            return "yes";
        }
    }
    return "no";
}

int main() {
    int t; cin >> t;
    while (t--) {
        long long n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;
        cout << isDrawGame(n, k, d1, d2) << endl;
    }
    return 0;
}