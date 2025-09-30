#include <iostream>

int main() {
    int a, b;
    while (std::cin >> a >> b) { // 注意 while 处理多个 case
        std::cout << a + b << std::endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")