#include <iostream>

auto func() -> bool {
    int a = 0, b = 0;
    std::cin >> a >> b;
    if (a == 0 && b == 0) {
        return false;
    } else {
        std::cout << a + b << std::endl;
        return true;
    }
}

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    bool temp = func();
    while (temp) {
        temp = func();
    }

    // int a, b;
    // while (std::cin >> a >> b) { // 注意 while 处理多个 case
    //     if (a == 0 and b == 0) { break; }
    //     std::cout << a + b << std::endl;
    // }

    return 0;
}

// 64 位输出请用 printf("%lld")