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

auto func() -> bool {
    int n = 0; // n \in [1, 100]
    cin >> n;
    if (n == 0) {
        return false;
    } else {
        gunc(n);
        return true;
    }
}

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    bool temp = func();
    while (temp) {
        temp = func();
    }
    return 0;
}