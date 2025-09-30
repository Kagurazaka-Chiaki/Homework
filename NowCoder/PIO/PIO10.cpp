#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string line;
    std::cin >> line;
    while (n--) {
        std::cout << line[n];
    }
    return 0;
}
// 64 位输出请用 printf("%lld")