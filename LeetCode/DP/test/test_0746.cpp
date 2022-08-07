
#include "dplib/solution.hpp"
#include <catch2/catch_test_macros.hpp>

#include <vector>

TEST_CASE("Test 0746") {
    auto S = dp::solution();

    auto const test_vec = std::vector<int>{
            1, 100, 1, 1, 1, 100, 1, 1, 100, 1, //
    };

    CHECK(S.minCostClimbingStairs(test_vec) == 6);
}