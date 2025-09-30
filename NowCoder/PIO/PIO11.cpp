#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string line;
        std::cin >> line;
        while (n--) {
            std::cout << line[n];
        }
        std::cout << std::endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")