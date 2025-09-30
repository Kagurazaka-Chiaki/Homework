#include <iostream>
#include <vector>

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::vector<long long> a(n, 1);
    a[n - 1] = m - n + 1;
    for (int const &i : a) {
        std::cout << i << ' ';
    }
    return 0;
}
// 64 位输出请用 printf("%lld")