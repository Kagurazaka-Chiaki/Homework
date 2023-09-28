//


#include "mat.hpp"
#include "vec.hpp"

#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>

TEST_CASE("vec") {
    SECTION("Basic") {
        auto test_vec = math::vec<3>();
        REQUIRE(test_vec[0] == 0);
        REQUIRE(test_vec[1] == 0);
        REQUIRE(test_vec[2] == 0);
        CHECK(test_vec == math::vec<3>({0, 0, 0}));

        auto test_vec_str = math::vec<3>({"1", "2", "3"});
        CHECK(test_vec_str == math::vec<3>({1, 2, 3}));
    }

    SECTION("Assign") {
        auto test_vec = math::vec<3>();
        test_vec[0] = 1;
        test_vec[1] = 2;
        test_vec[2] = 3;
        CHECK(test_vec == math::vec<3>({1, 2, 3}));
    }

    SECTION("Equal or Not") {
        auto test_vec_1 = math::vec<3>({0.9999, 2.00001, -3.00001});
        auto test_vec_2 = math::vec<3>({1, 2, -3});
        auto test_vec_3 = math::vec<3>({1, 2, -3});
        CHECK(test_vec_2 == test_vec_3);
        CHECK(test_vec_1 != test_vec_2);
    }

    SECTION("Copy and Move") {
        SECTION("Copy") {
            auto test_vec_ori = math::vec<3>({1, 2, 3});
            // force to create by copy constructor
            auto test_vec_copy = math::vec<3>(test_vec_ori);
            CHECK(test_vec_copy == math::vec<3>({1, 2, 3}));
        }

        SECTION("Move") {
            auto test_vec_ori = math::vec<3>({1, 2, 3});
            // force to create by move constructor
            auto test_vec_move = math::vec<3>(std::move(test_vec_ori));
            CHECK(test_vec_move == math::vec<3>({1, 2, 3}));
        }
    }

    SECTION("Add and Mult") {
        auto test_vec_1 = math::vec<3>({1, 2, 3});
        auto test_vec_2 = math::vec<3>({4, 5, 6});
        auto test_vec_add = test_vec_1 + test_vec_2;
        CHECK(test_vec_add == math::vec<3>({5, 7, 9}));

        auto test_vec_mult = test_vec_1 * 2;
        CHECK(test_vec_mult == math::vec<3>({2, 4, 6}));

        auto test_vec_mult_2 = 2 * test_vec_1;
        CHECK(test_vec_mult_2 == math::vec<3>({2, 4, 6}));

        auto test_vec_mult_3 = test_vec_1 * test_vec_2;
    }

    SECTION("Plus equal and Minus equal") {
        auto test_vec_1 = math::vec<3>({1, 2, 3});
        auto test_vec_2 = math::vec<3>({4, 5, 6});
        test_vec_1 += test_vec_2;
        CHECK(test_vec_1 == math::vec<3>({5, 7, 9}));
        test_vec_1 -= test_vec_2;
        CHECK(test_vec_1 == math::vec<3>({1, 2, 3}));
    }

    SECTION("Show") {
        auto test_vec = math::vec<3>({1, 2, 3});
        // auto str = static_cast<std::string>(test_vec);
        // CHECK(str == "[ 1.000000000000000 2.000000000000000 3.000000000000000 ]");
    }

    SECTION("Norm and Unit") {
        auto test_vec = math::vec<3>({1, 2, 3});
        CHECK(test_vec.norm() == Catch::Approx(3.741657386));
        CHECK(test_vec.norm(2) == Catch::Approx(3.741657386));
        CHECK(test_vec.norm(1) == Catch::Approx(6));
        CHECK(test_vec.norm(0) == Catch::Approx(3));

        auto test_vec_unit = test_vec.unit();
        CHECK(test_vec_unit[0] == Catch::Approx(0.267261241912424));
        CHECK(test_vec_unit[1] == Catch::Approx(0.534522483824849));
        CHECK(test_vec_unit[2] == Catch::Approx(0.801783725737273));
    }

    SECTION("Dot and Cross") {
        auto test_vec_1 = math::vec<3>({1, 2, 3});
        auto test_vec_2 = math::vec<3>({4, 5, 6});
        CHECK(test_vec_1.dot(test_vec_2) == 32);
        CHECK(test_vec_1.cross(test_vec_2) == math::vec<3>({-3, 6, -3}));
    }

    SECTION("Angle") {
        auto test_vec_1 = math::vec<3>({1, 2, 3});
        auto test_vec_2 = math::vec<3>({4, 5, 6});
        CHECK(test_vec_1.angle(test_vec_2) == Catch::Approx(0.225726128552734));
    }

    SECTION("Projection") {
        auto test_vec_1 = math::vec<3>({1, 2, 3});
        auto test_vec_2 = math::vec<3>({4, 5, 6});
        auto proj = test_vec_1.project(test_vec_2);
        CHECK(proj[0] == Catch::Approx(128.0 / 77.0));
        CHECK(proj[1] == Catch::Approx(160.0 / 77.0));
        CHECK(proj[2] == Catch::Approx(192.0 / 77.0));
    }

    SECTION("Rejection") {
        auto test_vec_1 = math::vec<3>({1, 2, 3});
        auto test_vec_2 = math::vec<3>({4, 5, 6});
        auto reject = test_vec_1.reject(test_vec_2);
        CHECK(reject[0] == Catch::Approx(1 - 128.0 / 77.0));
        CHECK(reject[1] == Catch::Approx(2 - 160.0 / 77.0));
        CHECK(reject[2] == Catch::Approx(3 - 192.0 / 77.0));
    }

    SECTION("Append") {
        auto test_vec_1 = math::vec<3>({1, 2, 3});
        auto test_vec_2 = test_vec_1.push(4);
        CHECK(test_vec_2 == math::vec<4>({1, 2, 3, 4}));
        auto test_vec_3 = test_vec_2.pop();
        CHECK(test_vec_3 == math::vec<3>({1, 2, 3}));
        auto test_vec_4 = test_vec_3.pop();
        CHECK(test_vec_4 == math::vec<2>({1, 2}));
        auto test_vec_5 = test_vec_4.pop();
        CHECK(test_vec_5 == math::vec<1>({1}));
        auto test_vec_6 = test_vec_5.pop();
    }

}