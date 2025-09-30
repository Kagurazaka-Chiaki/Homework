#include <iostream>

int main() {
    int T;
    std::cin >> T;
    while (T--) { // 注意 while 处理多个 case
        int a, b;
        std::cin >> a >> b;
        std::cout << a + b << std::endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")