

/**
 *
**/


#include "dplib/solution.hpp"

#include <iostream>

auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;
    /* code */
    std::cout << "Hello, 世界! \xF0\x9F\x98\x89 \n"
              << std::endl;

    auto &s = dp::solution::singleton();

    return 0;
}
