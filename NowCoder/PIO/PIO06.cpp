#include <iostream>


int main() {
    int n;
    std::cin >> n;
    long long sum = 0;
    while (n--) {
        long long a;
        std::cin >> a;
        sum += a;
    }
    std::cout << sum;
    return 0;
}
// 64 位输出请用 printf("%lld")