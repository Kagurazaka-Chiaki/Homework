#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

auto gunc(stringstream &s) -> vector<int> {
    int i = 0;
    vector<int> v;
    while (s >> i) {
        v.push_back(i);
    }
    return v;
}

auto func(stringstream &s) -> void {
    int sum = 0, temp = 0;
    while (s >> temp) {
        sum += temp;
    }
    cout << sum << endl;
}

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    string line;
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        // func(ss);
        auto vec = gunc(ss);
        // int result = 0;
        // std::for_each(vec.begin(), vec.end(), [&result](int x){ result += x; });
        // cout << result << endl;
        cout << accumulate(vec.begin(), vec.end(), 0) << endl;
    }

    return 0;
}
