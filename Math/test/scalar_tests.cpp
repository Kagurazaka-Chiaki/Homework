#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/scalar.hpp>

namespace epsilon::math {
    namespace {

        TEST_CASE("scalar constants and angle conversions") {
            CHECK(isNearlyEqual(radians(180.0F), kPi));
            CHECK(isNearlyEqual(radians(90.0F), kHalfPi));
            CHECK(isNearlyEqual(degrees(kPi), 180.0F));
            CHECK(isNearlyEqual(degrees(kTwoPi), 360.0F));

            CHECK(isNearlyEqual(radians(180.0), kPiV<f64>));
            CHECK(isNearlyEqual(degrees(kTwoPiV<f64>), 360.0));
        }

        TEST_CASE("scalar clamp and saturate constrain values") {
            CHECK(clamp(-1.0F, 0.0F, 1.0F) == 0.0F);
            CHECK(clamp(0.5F, 0.0F, 1.0F) == 0.5F);
            CHECK(clamp(2.0F, 0.0F, 1.0F) == 1.0F);

            CHECK(saturate(-0.25F) == 0.0F);
            CHECK(saturate(0.25F) == 0.25F);
            CHECK(saturate(1.25F) == 1.0F);
        }

        TEST_CASE("scalar helpers support interpolation and approximate comparison") {
            CHECK(square(3.0F) == 9.0F);
            CHECK(lerp(2.0F, 6.0F, 0.25F) == 3.0F);

            CHECK(isNearlyZero(0.5F * kEpsilon));
            CHECK_FALSE(isNearlyZero(2.0F * kEpsilon));

            CHECK(isNearlyEqual(1.0F, 1.0F + 0.5F * kEpsilon));
            CHECK_FALSE(isNearlyEqual(1.0F, 1.0F + 2.0F * kEpsilon));
        }

        TEST_CASE("scalar epsilon defaults follow value type") {
            CHECK(kEpsilonV<f32> == 1.0e-6F);
            CHECK(kEpsilonV<f64> == 1.0e-12);

            CHECK(isNearlyEqual(1.0F, 1.0F + 0.5F * kEpsilonV<f32>));
            CHECK_FALSE(isNearlyEqual(1.0F, 1.0F + 2.0F * kEpsilonV<f32>));

            CHECK(isNearlyEqual(1.0, 1.0 + 0.5 * kEpsilonV<f64>));
            CHECK_FALSE(isNearlyEqual(1.0, 1.0 + 2.0 * kEpsilonV<f64>));
        }

    } // namespace
} // namespace epsilon::math
