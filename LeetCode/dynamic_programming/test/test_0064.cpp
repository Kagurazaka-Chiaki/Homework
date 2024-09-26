#include "dplib/solution.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 0064") {
    auto &S = dp::solution::singleton();

    auto const test_vec = std::vector<std::vector<int>>{
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1},
    };

    CHECK(S.minPathSum(test_vec) == 7);
}
