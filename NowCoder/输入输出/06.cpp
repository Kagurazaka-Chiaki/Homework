#include <bits/stdc++.h>

using namespace std;

auto gunc(stringstream &s, int const &n) -> void {
    int sum = 0, temp = 0;
    for (int i = 0; i < n; i++) {
        s >> temp;
        sum += temp;
    }
    cout << sum << endl;
}

auto func(stringstream &s) -> void {
    int n = 0;
    s >> n;
    gunc(s, n);
}

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    string line;
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        func(ss);
    }

    return 0;
}