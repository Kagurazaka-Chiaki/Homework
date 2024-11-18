

#include <catch2/catch_test_macros.hpp>

#include "image.hpp"


TEST_CASE("test vision") {
   
   
    SECTION("001") {
        auto a = Image("gale.png");
        a.write_to_file("gale_copy.png");
        auto b = Image("gale_copy.png");
        for (int i = 0; i < a.size; ++i) {
            CHECK(a.data[i] == b.data[i]);
        }
    }


    // test copy constructor
    SECTION("002") {
        auto a = Image("gale.png");
        auto b = a;
        for (int i = 0; i < a.size; ++i) {
            CHECK(a.data[i] == b.data[i]);
        }
    }

    // test copy assignment
    SECTION("003") {
        auto a = Image("gale.png");
        auto b = Image("gale_copy.png");
        b = a;
        for (int i = 0; i < a.size; ++i) {
            CHECK(a.data[i] == b.data[i]);
        }
    }

    // test move constructor
    SECTION("004") {
        auto a = Image("gale.png");
        auto b = std::move(a);
        CHECK(a.data == nullptr);
        for (int i = 0; i < a.size; ++i) {
            CHECK(a.data[i] == b.data[i]);
        }
    }

    // test move assignment
    SECTION("005") {
        auto a = Image("gale.png");
        auto b = Image("gale_copy.png");
        b = std::move(a);
        CHECK(a.data == nullptr);
        for (int i = 0; i < a.size; ++i) {
            CHECK(a.data[i] == b.data[i]);
        }
    }


}