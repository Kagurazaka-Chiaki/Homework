// Contents: Test for SegmentTree

#include "SegmentTree.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test SegmentTree") {

    SECTION("Test Simple Get Sum (int)") {
        auto v = std::vector<int>(
                {10, 11, 12, 13, 14}
        );
        auto tree = Tree::SegmentTree<int>(v); // tree.print();
        REQUIRE(tree.get(0, 4) == 60);
        REQUIRE(tree.get(0, 2) == 33);
        REQUIRE(tree.get(3, 4) == 27);
        REQUIRE(tree.get(0, 1) == 21);
        REQUIRE(tree.get(1, 3) == 36);
        REQUIRE(tree.get(0, 0) == 10);
        REQUIRE(tree.get(1, 1) == 11);
        REQUIRE(tree.get(2, 2) == 12);
        REQUIRE(tree.get(3, 3) == 13);
        REQUIRE(tree.get(4, 4) == 14);
    }

    SECTION("Test Simple Get Sum (double)") {
        auto v = std::vector<double>(
                {3.14, 2.71, 1.41, 1.61, 1.73}
        );
        auto tree = Tree::SegmentTree<double>(v);
        // tree.print();
        REQUIRE(tree.get(0, 4) == 10.6);
        REQUIRE(tree.get(0, 2) == 7.26);
        REQUIRE(tree.get(3, 4) == 3.34);
        REQUIRE(tree.get(0, 1) == 5.85);
        REQUIRE(tree.get(1, 3) == 5.73);
        REQUIRE(tree.get(0, 0) == 3.14);
        REQUIRE(tree.get(1, 1) == 2.71);
        REQUIRE(tree.get(2, 2) == 1.41);
        REQUIRE(tree.get(3, 3) == 1.61);
        REQUIRE(tree.get(4, 4) == 1.73);
    }
}