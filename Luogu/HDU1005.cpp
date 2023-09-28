

// f(1) = 1; f(2) = 1; f(n) = A f(n - 1) + B f(n - 1)
// A B 1000, n < 1e8
// 矩阵乘法快速幂
// U = [A B | 1 0] [f(n - 1) f(n - 2)] = [f(n) f(n - 1)]


/**
 *
**/


#include <iostream>


auto main(int argc, char const *argv[]) -> int {
    (void) argc; (void) argv;
    /* code */
    std::cout << "Hello, 世界! \xF0\x9F\x98\x89 \n" << std::endl;
    return 0;
}
