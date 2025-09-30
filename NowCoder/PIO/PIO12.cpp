#include <algorithm>
#include <iostream>
#include <vector>


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    while (n--) {
        std::cin >> a[n];
        std::reverse(a[n].begin(), a[n].end());
    }
    for (auto const &s : a) {
        std::cout << s << '\n';
    }
    return 0;
}
// 64 位输出请用 printf("%lld")