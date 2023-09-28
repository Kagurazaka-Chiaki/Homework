//


#include <iostream>

auto func() -> void {
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << a + b << std::endl;
}

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    int t = 0; // t \in [1, 100]
    std::cin >> t;
    while (t <= 100 && t >= 1) {
        func();
        t--;
    }
    return 0;
}
