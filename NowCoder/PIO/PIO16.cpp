#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    std::cout << (n % 2 == 0 ? "NO" : "YES");
    return 0;
}
// 64 位输出请用 printf("%lld")