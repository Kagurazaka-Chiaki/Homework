//

#include "dplib/solution.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Factorial of 0 is 1 (fail)", "[single-file]") {
    auto &test_fib = dp::solution::singleton();
    REQUIRE(test_fib.fib(0) == 1);
}

TEST_CASE("Factorials of 1 and higher are computed (pass)", "[single-file]") {
    auto &test_fib = dp::solution::singleton();
    REQUIRE(test_fib.fib(1) == 1);
    REQUIRE(test_fib.fib(2) == 1);
    REQUIRE(test_fib.fib(3) == 2);
    REQUIRE(test_fib.fib(10) == 55);
}
