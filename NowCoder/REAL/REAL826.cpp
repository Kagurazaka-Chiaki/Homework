#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

// 41 40 39 38 37 36 35
// 39

int main() {
    int n = 7;
    int t = 0;
    std::vector<int> vt;
    while(n-- && std::cin >> t) {
        vt.emplace_back(t);
    }
    int ans = 0;
    for (auto const &t : vt) {
        if (t > 40) {
            ans += 4;
        } else if (t >= 38 && t <= 40) {
            ans += 5;
        } else if (t > 35 && t < 38) {
            ans += 6;
        } else if (t <= 35) {
            ans += 8;
        }
    }
    printf("%d", ans);
    return EXIT_SUCCESS;
}
// 64 位输出请用 printf("%lld")