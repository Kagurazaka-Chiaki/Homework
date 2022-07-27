/**
 *
**/

#include <iostream>
#include <bits/stdc++.h>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

auto main(int argc, char const *argv[]) -> int {
    (void) argc; (void) argv;
    std::cout << "Hello, World! \xF0\x9F\x98\x89 \n" << std::endl;

    MatrixXd mat1(3, 3);

    MatrixXd mat2(3, 3);
    mat1(0, 0) = 1.3;
    mat2(0, 0) = 1.3;
    auto k = mat1 == mat2;
    cout << mat1 << k << endl;
    return 0;
}
