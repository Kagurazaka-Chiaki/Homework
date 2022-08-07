#include <bits/stdc++.h>

using namespace std;

auto func() -> void {
    int a = 0, b = 0;
    cin >> a >> b;
    cout << a + b << endl;
}

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    int t = 0; // t \in [1, 100]
    cin >> t;
    while (t <= 100 && t >= 1) {
        func();
        t--;
    }
    return 0;
}
