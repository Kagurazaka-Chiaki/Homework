
#include "dplib/solution.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test 0746") {
    auto &S = dp::solution::singleton();

    SECTION("test 1") {
        auto const test_vec = std::vector<int>{
                10,
                15,
                20,
        };

        CHECK(S.minCostClimbingStairs(test_vec) == 15);
    }


    SECTION("test 2") {
        auto const test_vec = std::vector<int>{
                1, 100, 1, 1, 1, 100, 1, 1, 100, 1, //
        };

        CHECK(S.minCostClimbingStairs(test_vec) == 6);
    }
}