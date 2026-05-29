#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/vector.hpp>

namespace epsilon::math {
    namespace {

        TEST_CASE("vec aggregate header exposes common vector types") {
            CHECK(Vec2{1.0F, 2.0F}.x == 1.0F);
            CHECK(Vec3{1.0F, 2.0F, 3.0F}.z == 3.0F);
            CHECK(Vec4{1.0F, 2.0F, 3.0F, 4.0F}.w == 4.0F);
        }

    } // namespace
} // namespace epsilon::math
