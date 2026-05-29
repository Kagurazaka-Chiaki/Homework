#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/matrix.hpp>

namespace epsilon::math {
    namespace {

        TEST_CASE("Mat2x2 aliases and default construction") {
            CHECK(sizeof(Mat2x2) == sizeof(Mat2x2f));
            CHECK(sizeof(Mat2x2d) == sizeof(f64) * 4);
            CHECK(Mat2x2::zero() == Mat2x2{});

            Mat2x2 value{};
            value(0, 0) = 1.0F;
            value(0, 1) = 2.0F;
            value(1, 0) = 3.0F;
            value(1, 1) = 4.0F;
            value[1][1] = 5.0F;

            Scalar const *flat = value.raw();
            CHECK(flat[0] == 1.0F);
            CHECK(flat[1] == 2.0F);
            CHECK(flat[2] == 3.0F);
            CHECK(flat[3] == 5.0F);
            CHECK(value(1, 1) == 5.0F);
            CHECK(&value[1][1] == &value(1, 1));

            Mat2x2 const const_value = value;
            CHECK(const_value.raw()[3] == 5.0F);
            CHECK(const_value[1][1] == 5.0F);
        }

        TEST_CASE("Mat2x2 identity transpose and component arithmetic") {
            Mat2x2 const value = {
                {1.0F, 2.0F},
                {3.0F, 4.0F},
            };
            Mat2x2 const other = {
                {5.0F, 6.0F},
                {7.0F, 8.0F},
            };
            Mat2x2 const flat = {1.0F, 2.0F, 3.0F, 4.0F};
            Mat2x2 const rows = {
                {1.0F, 2.0F},
                {3.0F, 4.0F},
            };
            Mat2x2 const partial          = {1.0F, 2.0F, 3.0F};
            Mat2x2 const extra            = {1.0F, 2.0F, 3.0F, 4.0F, 5.0F};
            Mat2x2 const expected_partial = {
                {1.0F, 2.0F},
                {3.0F, 0.0F},
            };
            Mat2x2 const expected_transpose = {
                {1.0F, 3.0F},
                {2.0F, 4.0F},
            };
            Mat2x2 const expected_sum = {
                { 6.0F,  8.0F},
                {10.0F, 12.0F},
            };
            Mat2x2 const expected_difference = {
                {4.0F, 4.0F},
                {4.0F, 4.0F},
            };
            Mat2x2 const expected_negated = {
                {-1.0F, -2.0F},
                {-3.0F, -4.0F},
            };
            Mat2x2 const expected_scaled = {
                {2.0F, 4.0F},
                {6.0F, 8.0F},
            };
            Mat2x2 const expected_halved = {
                {0.5F, 1.0F},
                {1.5F, 2.0F},
            };

            CHECK(flat == value);
            CHECK(rows == value);
            CHECK(partial == expected_partial);
            CHECK(extra == value);
            CHECK(Mat2x2::identity() * Vec2{2.0F, 3.0F} == Vec2{2.0F, 3.0F});
            CHECK(transpose(value) == expected_transpose);
            CHECK(value + other == expected_sum);
            CHECK(other - value == expected_difference);
            CHECK(-value == expected_negated);
            CHECK(value * 2.0F == expected_scaled);
            CHECK(2.0F * value == expected_scaled);
            CHECK(value / 2.0F == expected_halved);
        }

        TEST_CASE("Mat2x2 compound matrix multiplication vector multiplication and nearly equal") {
            Mat2x2 const value = {
                {1.0F, 2.0F},
                {3.0F, 4.0F},
            };
            Mat2x2 const other = {
                {5.0F, 6.0F},
                {7.0F, 8.0F},
            };
            Mat2x2       changed      = value;
            Mat2x2 const expected_sum = {
                { 6.0F,  8.0F},
                {10.0F, 12.0F},
            };
            Mat2x2 const expected_scaled = {
                {2.0F, 4.0F},
                {6.0F, 8.0F},
            };
            Mat2x2 const expected_product = {
                {19.0F, 22.0F},
                {43.0F, 50.0F},
            };

            changed += other;
            CHECK(changed == expected_sum);

            changed -= other;
            CHECK(changed == value);

            changed *= 2.0F;
            CHECK(changed == expected_scaled);

            changed /= 2.0F;
            CHECK(changed == value);

            CHECK(value * other == expected_product);
            CHECK(value * Vec2{5.0F, 6.0F} == Vec2{17.0F, 39.0F});

            Mat2x2d near = Mat2x2d::identity();
            near(0, 1)   = 0.5 * kEpsilonV<f64>;
            CHECK(isNearlyEqual(near, Mat2x2d::identity()));

            near(0, 1) = 2.0 * kEpsilonV<f64>;
            CHECK_FALSE(isNearlyEqual(near, Mat2x2d::identity()));
        }

    } // namespace
} // namespace epsilon::math
