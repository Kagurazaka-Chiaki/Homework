#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/matrix.hpp>

namespace epsilon::math {
    namespace {

        TEST_CASE("Mat3x3 aliases and default construction") {
            CHECK(sizeof(Mat3x3) == sizeof(Mat3x3f));
            CHECK(sizeof(Mat3x3d) == sizeof(f64) * 9);
            CHECK(Mat3x3::zero() == Mat3x3{});

            Mat3x3 value{};
            value(0, 0) = 1.0F;
            value(0, 1) = 2.0F;
            value(0, 2) = 3.0F;
            value(1, 0) = 4.0F;
            value[1][1] = 5.0F;

            Scalar const *flat = value.raw();
            CHECK(flat[0] == 1.0F);
            CHECK(flat[1] == 2.0F);
            CHECK(flat[2] == 3.0F);
            CHECK(flat[3] == 4.0F);
            CHECK(flat[4] == 5.0F);
            CHECK(value(1, 1) == 5.0F);
            CHECK(&value[1][1] == &value(1, 1));

            Mat3x3 const const_value = value;
            CHECK(const_value.raw()[4] == 5.0F);
            CHECK(const_value[1][1] == 5.0F);
        }

        TEST_CASE("Mat3x3 identity transpose and component arithmetic") {
            Mat3x3 const value = {
                {1.0F, 2.0F, 3.0F},
                {4.0F, 5.0F, 6.0F},
                {7.0F, 8.0F, 9.0F},
            };
            Mat3x3 const other = {
                {9.0F, 8.0F, 7.0F},
                {6.0F, 5.0F, 4.0F},
                {3.0F, 2.0F, 1.0F},
            };
            Mat3x3 const flat = {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F};
            Mat3x3 const rows = {
                {1.0F, 2.0F, 3.0F},
                {4.0F, 5.0F, 6.0F},
                {7.0F, 8.0F, 9.0F},
            };
            Mat3x3 const partial          = {1.0F, 2.0F, 3.0F, 4.0F};
            Mat3x3 const extra            = {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F};
            Mat3x3 const expected_partial = {
                {1.0F, 2.0F, 3.0F},
                {4.0F, 0.0F, 0.0F},
                {0.0F, 0.0F, 0.0F},
            };
            Mat3x3 const expected_transpose = {
                {1.0F, 4.0F, 7.0F},
                {2.0F, 5.0F, 8.0F},
                {3.0F, 6.0F, 9.0F},
            };
            Mat3x3 const expected_sum = {
                {10.0F, 10.0F, 10.0F},
                {10.0F, 10.0F, 10.0F},
                {10.0F, 10.0F, 10.0F},
            };
            Mat3x3 const expected_difference = {
                { 8.0F,  6.0F,  4.0F},
                { 2.0F,  0.0F, -2.0F},
                {-4.0F, -6.0F, -8.0F},
            };
            Mat3x3 const expected_negated = {
                {-1.0F, -2.0F, -3.0F},
                {-4.0F, -5.0F, -6.0F},
                {-7.0F, -8.0F, -9.0F},
            };
            Mat3x3 const expected_scaled = {
                { 2.0F,  4.0F,  6.0F},
                { 8.0F, 10.0F, 12.0F},
                {14.0F, 16.0F, 18.0F},
            };
            Mat3x3 const expected_halved = {
                {0.5F, 1.0F, 1.5F},
                {2.0F, 2.5F, 3.0F},
                {3.5F, 4.0F, 4.5F},
            };

            CHECK(flat == value);
            CHECK(rows == value);
            CHECK(partial == expected_partial);
            CHECK(extra == value);
            CHECK(Mat3x3::identity() * Vec3{2.0F, 3.0F, 4.0F} == Vec3{2.0F, 3.0F, 4.0F});
            CHECK(transpose(value) == expected_transpose);
            CHECK(value + other == expected_sum);
            CHECK(other - value == expected_difference);
            CHECK(-value == expected_negated);
            CHECK(value * 2.0F == expected_scaled);
            CHECK(value / 2.0F == expected_halved);
        }

        TEST_CASE("Mat3x3 compound matrix multiplication vector multiplication and nearly equal") {
            Mat3x3 const value = {
                {1.0F, 2.0F, 3.0F},
                {4.0F, 5.0F, 6.0F},
                {7.0F, 8.0F, 9.0F},
            };
            Mat3x3 const other = {
                {9.0F, 8.0F, 7.0F},
                {6.0F, 5.0F, 4.0F},
                {3.0F, 2.0F, 1.0F},
            };
            Mat3x3       changed      = value;
            Mat3x3 const expected_sum = {
                {10.0F, 10.0F, 10.0F},
                {10.0F, 10.0F, 10.0F},
                {10.0F, 10.0F, 10.0F},
            };
            Mat3x3 const expected_scaled = {
                { 2.0F,  4.0F,  6.0F},
                { 8.0F, 10.0F, 12.0F},
                {14.0F, 16.0F, 18.0F},
            };
            Mat3x3 const expected_product = {
                { 30.0F,  24.0F, 18.0F},
                { 84.0F,  69.0F, 54.0F},
                {138.0F, 114.0F, 90.0F},
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
            CHECK(value * Vec3{1.0F, 2.0F, 3.0F} == Vec3{14.0F, 32.0F, 50.0F});

            Mat3x3d near = Mat3x3d::identity();
            near(0, 2)   = 0.5 * kEpsilonV<f64>;
            CHECK(isNearlyEqual(near, Mat3x3d::identity()));

            near(0, 2) = 2.0 * kEpsilonV<f64>;
            CHECK_FALSE(isNearlyEqual(near, Mat3x3d::identity()));
        }

    } // namespace
} // namespace epsilon::math
