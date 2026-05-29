#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/vector.hpp>

#include <cmath>

namespace epsilon::math {
    namespace {

        TEST_CASE("vec4 aliases use the default scalar type") {
            CHECK(sizeof(Vec4) == sizeof(Vec4f));
            CHECK(sizeof(Vec4d) == sizeof(f64) * 4);
        }

        TEST_CASE("vec4 supports indexed component access") {
            Vec4 value{1.0F, 2.0F, 3.0F, 4.0F};

            CHECK(value(0) == 1.0F);
            CHECK(value(1) == 2.0F);
            CHECK(value(2) == 3.0F);
            CHECK(value(3) == 4.0F);
            CHECK(value[0] == 1.0F);
            CHECK(value[1] == 2.0F);
            CHECK(value[2] == 3.0F);
            CHECK(value[3] == 4.0F);

            value(0) = 5.0F;
            value[1] = 6.0F;
            value(2) = 7.0F;
            value[3] = 8.0F;
            CHECK(value == Vec4{5.0F, 6.0F, 7.0F, 8.0F});

            Vec4 const const_value = value;
            CHECK(const_value(0) == 5.0F);
            CHECK(const_value[1] == 6.0F);
            CHECK(const_value(2) == 7.0F);
            CHECK(const_value[3] == 8.0F);
        }

        TEST_CASE("vec4 arithmetic works component-wise") {
            Vec4 const original{1.0F, 2.0F, 3.0F, 4.0F};
            Vec4       value = original;

            CHECK(value + Vec4{5.0F, 6.0F, 7.0F, 8.0F} == Vec4{6.0F, 8.0F, 10.0F, 12.0F});
            CHECK(value - Vec4{0.5F, 1.0F, 1.5F, 2.0F} == Vec4{0.5F, 1.0F, 1.5F, 2.0F});
            CHECK(-value == Vec4{-1.0F, -2.0F, -3.0F, -4.0F});
            CHECK(value == original);
            CHECK(value * 2.0F == Vec4{2.0F, 4.0F, 6.0F, 8.0F});
            CHECK(2.0F * value == Vec4{2.0F, 4.0F, 6.0F, 8.0F});
            CHECK(value / 2.0F == Vec4{0.5F, 1.0F, 1.5F, 2.0F});

            value += Vec4{1.0F, 1.0F, 1.0F, 1.0F};
            CHECK(value == Vec4{2.0F, 3.0F, 4.0F, 5.0F});

            value -= Vec4{1.0F, 1.0F, 1.0F, 1.0F};
            CHECK(value == original);

            value *= 2.0F;
            CHECK(value == Vec4{2.0F, 4.0F, 6.0F, 8.0F});

            value /= 2.0F;
            CHECK(value == original);
        }

        TEST_CASE("vec4 dot length normalization and comparison work") {
            CHECK(dot(Vec4{1.0F, 2.0F, 3.0F, 4.0F}, Vec4{5.0F, 6.0F, 7.0F, 8.0F}) == 70.0F);
            CHECK(normSquared(Vec4{1.0F, 2.0F, 2.0F, 4.0F}) == 25.0F);
            CHECK(isNearlyEqual(length(Vec4{1.0F, 2.0F, 2.0F, 4.0F}), 5.0F));
            CHECK(normalized(Vec4{}) == Vec4{});
            CHECK(isNearlyEqual(normalized(Vec4{0.0F, 0.0F, 0.0F, 5.0F}), Vec4{0.0F, 0.0F, 0.0F, 1.0F}));
        }

        TEST_CASE("vec4 norm supports common orders") {
            Vec4 const value{-1.0F, 2.0F, -2.0F, 4.0F};

            CHECK(norm(value, 0) == 4.0F);
            CHECK(norm(value, 1) == 9.0F);
            CHECK(isNearlyEqual(norm(value, 2), 5.0F));
            CHECK(isNearlyEqual(norm(value, 3), std::cbrt(81.0F)));
            CHECK(isNearlyEqual(norm(value, 4), std::pow(289.0F, 0.25F)));
            CHECK(norm(value, -1) == 0.0F);
        }

    } // namespace
} // namespace epsilon::math
