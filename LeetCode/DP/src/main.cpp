/**
 *
**/


#include <bits/stdc++.h>
#include <cstdio>
#include <type_traits>

using namespace std;

#include "dplib/solution.hpp"

auto main(int argc, char const *argv[]) -> int {
    (void) argc; (void) argv;
    /* code */

    auto S = dp::solution();
    std::cout << S.fib(1) << std::endl;

    return 0;
}
