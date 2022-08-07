#include <bits/stdc++.h>

using namespace std;


auto gunc(int const &n) -> void {
    int sum = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
    }
    cout << sum << endl;
}

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    int t = 0; // t \in [1, 100]
    cin >> t;
    while (t--) {
        int n = 0; // n \in [1, 100]
        cin >> n;
        gunc(n);
    }
    return 0;
}