#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/vector.hpp>

#include <cmath>

namespace epsilon::math {
    namespace {

        TEST_CASE("vec2 aliases use the default scalar type") {
            CHECK(sizeof(Vec2) == sizeof(Vec2f));
            CHECK(sizeof(Vec2d) == sizeof(f64) * 2);
        }

        TEST_CASE("vec2 supports indexed component access") {
            Vec2 value{1.0F, 2.0F};

            CHECK(value(0) == 1.0F);
            CHECK(value(1) == 2.0F);
            CHECK(value[0] == 1.0F);
            CHECK(value[1] == 2.0F);

            value(0) = 3.0F;
            value[1] = 4.0F;
            CHECK(value == Vec2{3.0F, 4.0F});

            Vec2 const const_value = value;
            CHECK(const_value(0) == 3.0F);
            CHECK(const_value[1] == 4.0F);
        }

        TEST_CASE("vec2 arithmetic works component-wise") {
            Vec2 const original{1.0F, 2.0F};
            Vec2       value = original;

            CHECK(value + Vec2{3.0F, 4.0F} == Vec2{4.0F, 6.0F});
            CHECK(value - Vec2{0.5F, 1.0F} == Vec2{0.5F, 1.0F});
            CHECK(-value == Vec2{-1.0F, -2.0F});
            CHECK(value == original);
            CHECK(value * 2.0F == Vec2{2.0F, 4.0F});
            CHECK(2.0F * value == Vec2{2.0F, 4.0F});
            CHECK(value / 2.0F == Vec2{0.5F, 1.0F});

            value += Vec2{1.0F, 1.0F};
            CHECK(value == Vec2{2.0F, 3.0F});

            value -= Vec2{1.0F, 1.0F};
            CHECK(value == original);

            value *= 2.0F;
            CHECK(value == Vec2{2.0F, 4.0F});

            value /= 2.0F;
            CHECK(value == original);
        }

        TEST_CASE("vec2 dot length normalization and comparison work") {
            CHECK(dot(Vec2{1.0F, 2.0F}, Vec2{3.0F, 4.0F}) == 11.0F);
            CHECK(normSquared(Vec2{3.0F, 4.0F}) == 25.0F);
            CHECK(isNearlyEqual(length(Vec2{3.0F, 4.0F}), 5.0F));
            CHECK(normalized(Vec2{}) == Vec2{});
            CHECK(isNearlyEqual(normalized(Vec2{3.0F, 4.0F}), Vec2{0.6F, 0.8F}));
        }

        TEST_CASE("vec2 norm supports common orders") {
            Vec2 const value{-3.0F, 4.0F};

            CHECK(norm(value, 0) == 4.0F);
            CHECK(norm(value, 1) == 7.0F);
            CHECK(isNearlyEqual(norm(value, 2), 5.0F));
            CHECK(isNearlyEqual(norm(value, 3), std::cbrt(91.0F)));
            CHECK(isNearlyEqual(norm(value, 4), std::pow(337.0F, 0.25F)));
            CHECK(norm(value, -1) == 0.0F);
        }

    } // namespace
} // namespace epsilon::math
