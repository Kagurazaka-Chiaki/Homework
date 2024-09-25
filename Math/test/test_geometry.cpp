

#include "geometry.hpp"
#include "vec.hpp"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Geometry") {
    SECTION("Area 0") {

        auto p1 = math::point<3>(
                {1, 2, 3}
        );
        auto p2 = math::point<3>(
                {1, 2, 3}
        );
        auto p3 = math::point<3>(
                {1, 2, 3}
        );

        // distance
        REQUIRE(math::distance(p1, p2) == 0);
        REQUIRE(math::triangle_area(p1, p2, p3) == 0);
    }

    SECTION("Area 3.72833897") {

        auto p1 = math::point<3>(
                {0, 0, 0}
        );
        auto p2 = math::point<3>(
                {2, 0, 0}
        );
        auto p3 = math::point<3>(
                {1.754806155676498, -2.558013688392027, 2.712391940730655}
        );

        // distance
        REQUIRE(math::distance(p1, p2) == 2);
        REQUIRE(math::triangle_area(p1, p2, p3) == Catch::Approx(3.72833897));
    }

    SECTION("Project to (1.395887, 0.650574, 0.000000)") {

        auto p1 = math::vec<3>(
                {1, 1.5, 0}
        );
        auto p2 = math::vec<3>(
                {2.8413285152858, 1.3242422589643, 0}
        );

        auto p3 = p1.project(p2);

        REQUIRE(p3[0] == Catch::Approx(1.395887));
        REQUIRE(p3[1] == Catch::Approx(0.650574));
        REQUIRE(p3[2] == 0);
    }


    SECTION("Point Project In Triangle") {

        auto t1 = math::triangle{
                {0,                 0,                  0                 },
                {2.752631535015455, 3.81220908497157,   -3.160394755084511},
                {5.052341847754612, -4.561236070691592, 1.7580024991465   }
        };
        auto const &p1 = math::vec<3>{1, 2, 3};
        auto b1 = math::is_project_in_triangle(p1, t1);
        REQUIRE(b1 == true);

        auto t2 = math::triangle{
                {0, 0, 0},
                {1, 0, 0},
                {0, 1, 0}
        };
        auto p2 = math::vec<3>{0.5, 0.5, 0};
        auto b2 = math::is_project_in_triangle(p2, t2);
        REQUIRE(b2 == true);

        auto t3 = math::triangle{
                {0, 0, 0},
                {1, 0, 0},
                {0, 1, 0}
        };
        auto p3 = math::vec<3>{0.5, 0.6, 1};
        auto b3 = math::is_project_in_triangle(p3, t3);
        REQUIRE(b3 == false);

        auto t4 = math::triangle{
                {0,                 0,                  0                 },
                {2.752631535015455, 3.81220908497157,   -3.160394755084511},
                {1.674037191159544, -2.825866005880165, 1.7580024991465   }
        };
        auto p4 = math::vec<3>(
                {-0.939765824829497, 6.185378842752051, 3}
        );
        auto b4 = math::is_project_in_triangle(p4, t4);
        REQUIRE(b4 == false);
    }
}