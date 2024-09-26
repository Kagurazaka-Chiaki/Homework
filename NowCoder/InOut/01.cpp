/**
 *
**/


#include <iostream>

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    int a = 0, b = 0;
    while (std::cin >> a >> b) {
        std::cout << a + b << std::endl;
    }
    return 0;
}