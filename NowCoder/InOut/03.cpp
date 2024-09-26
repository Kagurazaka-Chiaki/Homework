//

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
    return 0;
}
