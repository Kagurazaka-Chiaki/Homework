//

#include <catch2/catch_test_macros.hpp>

#include "dplib/solution.hpp"

TEST_CASE("Test 1143") {
    auto &S = dp::solution::singleton();

    auto text_1 = "abcde";
    auto text_2 = "ace";

    CHECK(S.longestCommonSubsequence(text_1, text_2) == 3);
}