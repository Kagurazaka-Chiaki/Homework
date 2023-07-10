/**
 *
**/

#include <iostream>
// #include <bits/stdc++.h>

#include <Eigen/Dense>

auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;
    // system("chcp 65001");
    std::cout << "你好, 世界。 \xF0\x9F\x98\x89 \n"
              << std::endl;

    Eigen::MatrixXd mat1(3, 3);

    Eigen::MatrixXd mat2(3, 3);

    mat1 << 1, 2, 3, 4, 5, 6, 7, 8, 9;

    mat1(0, 0) = 1.3;
    mat2(0, 0) = 1.3;
    auto k = mat1 == mat2;
    std::cout << mat1 << '\n'
              << k << std::endl;
    return 0;
}
