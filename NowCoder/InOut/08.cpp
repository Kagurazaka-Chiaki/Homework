/**
 *
**/


#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    int n = 0;
    cin >> n;
    vector<string> v;
    while (n--) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for (auto const &i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}