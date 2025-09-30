#include <cstdio>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        long long sum = 0LL;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                long long a;
                std::cin >> a;
                sum += a;
            }
        }
        printf("%lld\n", sum);
    }
}
// 64 位输出请用 printf("%lld")