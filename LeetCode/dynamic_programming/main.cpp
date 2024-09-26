/**
 *
**/


#include "dplib/solution.hpp"

#include <iostream>
#include <vector>

auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;
    /* code */

    auto &S = dp::solution::singleton();

    std::cout << S.fib(1) << std::endl;

    auto test_vec = std::vector<int>({10, 9, 2, 5, 3, 7, 101, 18});
    std::cout << S.lengthOfLIS(test_vec) << std::endl;


    return 0;
}
