/**
 *
**/


#include <bits/stdc++.h>

using namespace std;

auto gunc(vector<string> &vec) -> void {
    sort(vec.begin(), vec.end());
    for (auto const &i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

auto func(stringstream &s) -> vector<string> {
    string i;
    vector<string> v;
    while (s >> i) {
        v.push_back(i);
    }
    return v;
}

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    string line;
    while (getline(cin, line)) {
        stringstream s;
        s << line;
        auto vec = func(s);
        gunc(vec);
    }
    return 0;
}
