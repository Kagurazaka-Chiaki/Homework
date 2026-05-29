#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/matrix.hpp>

namespace epsilon::math {
    namespace {

        TEST_CASE("Mat4x4 aliases and default construction") {
            CHECK(sizeof(Mat4x4) == sizeof(Mat4x4f));
            CHECK(sizeof(Mat4x4d) == sizeof(f64) * 16);
            CHECK(Mat4x4::zero() == Mat4x4{});

            Mat4x4 value{};
            value(0, 0) = 1.0F;
            value(0, 1) = 2.0F;
            value(0, 2) = 3.0F;
            value(0, 3) = 4.0F;
            value(1, 0) = 5.0F;
            value[1][1] = 6.0F;

            Scalar const *flat = value.raw();
            CHECK(flat[0] == 1.0F);
            CHECK(flat[1] == 2.0F);
            CHECK(flat[2] == 3.0F);
            CHECK(flat[3] == 4.0F);
            CHECK(flat[4] == 5.0F);
            CHECK(flat[5] == 6.0F);
            CHECK(value(1, 1) == 6.0F);
            CHECK(&value[1][1] == &value(1, 1));

            Mat4x4 const const_value = value;
            CHECK(const_value.raw()[5] == 6.0F);
            CHECK(const_value[1][1] == 6.0F);
        }

        TEST_CASE("Mat4x4 identity transpose and component arithmetic") {
            Mat4x4 const value = {
                { 1.0F,  2.0F,  3.0F,  4.0F},
                { 5.0F,  6.0F,  7.0F,  8.0F},
                { 9.0F, 10.0F, 11.0F, 12.0F},
                {13.0F, 14.0F, 15.0F, 16.0F},
            };
            Mat4x4 const flat = {
                1.0F,
                2.0F,
                3.0F,
                4.0F,
                5.0F,
                6.0F,
                7.0F,
                8.0F,
                9.0F,
                10.0F,
                11.0F,
                12.0F,
                13.0F,
                14.0F,
                15.0F,
                16.0F,
            };
            Mat4x4 const rows = {
                { 1.0F,  2.0F,  3.0F,  4.0F},
                { 5.0F,  6.0F,  7.0F,  8.0F},
                { 9.0F, 10.0F, 11.0F, 12.0F},
                {13.0F, 14.0F, 15.0F, 16.0F},
            };
            Mat4x4 const partial = {
                1.0F,
                2.0F,
                3.0F,
                4.0F,
                5.0F,
            };
            Mat4x4 const extra = {
                1.0F,
                2.0F,
                3.0F,
                4.0F,
                5.0F,
                6.0F,
                7.0F,
                8.0F,
                9.0F,
                10.0F,
                11.0F,
                12.0F,
                13.0F,
                14.0F,
                15.0F,
                16.0F,
                17.0F,
            };
            Mat4x4 const ones = {
                {1.0F, 1.0F, 1.0F, 1.0F},
                {1.0F, 1.0F, 1.0F, 1.0F},
                {1.0F, 1.0F, 1.0F, 1.0F},
                {1.0F, 1.0F, 1.0F, 1.0F},
            };
            Mat4x4 const expected_partial = {
                {1.0F, 2.0F, 3.0F, 4.0F},
                {5.0F, 0.0F, 0.0F, 0.0F},
                {0.0F, 0.0F, 0.0F, 0.0F},
                {0.0F, 0.0F, 0.0F, 0.0F},
            };
            Mat4x4 const expected_transpose = {
                {1.0F, 5.0F,  9.0F, 13.0F},
                {2.0F, 6.0F, 10.0F, 14.0F},
                {3.0F, 7.0F, 11.0F, 15.0F},
                {4.0F, 8.0F, 12.0F, 16.0F},
            };
            Mat4x4 const expected_sum = {
                { 2.0F,  3.0F,  4.0F,  5.0F},
                { 6.0F,  7.0F,  8.0F,  9.0F},
                {10.0F, 11.0F, 12.0F, 13.0F},
                {14.0F, 15.0F, 16.0F, 17.0F},
            };
            Mat4x4 const expected_difference = {
                { 0.0F,  1.0F,  2.0F,  3.0F},
                { 4.0F,  5.0F,  6.0F,  7.0F},
                { 8.0F,  9.0F, 10.0F, 11.0F},
                {12.0F, 13.0F, 14.0F, 15.0F},
            };
            Mat4x4 const expected_negated = {
                {-1.0F, -1.0F, -1.0F, -1.0F},
                {-1.0F, -1.0F, -1.0F, -1.0F},
                {-1.0F, -1.0F, -1.0F, -1.0F},
                {-1.0F, -1.0F, -1.0F, -1.0F},
            };
            Mat4x4 const expected_scaled = {
                {2.0F, 2.0F, 2.0F, 2.0F},
                {2.0F, 2.0F, 2.0F, 2.0F},
                {2.0F, 2.0F, 2.0F, 2.0F},
                {2.0F, 2.0F, 2.0F, 2.0F},
            };
            Mat4x4 const expected_halved = {
                {0.5F, 0.5F, 0.5F, 0.5F},
                {0.5F, 0.5F, 0.5F, 0.5F},
                {0.5F, 0.5F, 0.5F, 0.5F},
                {0.5F, 0.5F, 0.5F, 0.5F},
            };

            CHECK(flat == value);
            CHECK(rows == value);
            CHECK(partial == expected_partial);
            CHECK(extra == value);
            CHECK(Mat4x4::identity() * Vec4{2.0F, 3.0F, 4.0F, 5.0F} == Vec4{2.0F, 3.0F, 4.0F, 5.0F});
            CHECK(transpose(value) == expected_transpose);
            CHECK(value + ones == expected_sum);
            CHECK(value - ones == expected_difference);
            CHECK(-ones == expected_negated);
            CHECK(ones * 2.0F == expected_scaled);
            CHECK(ones / 2.0F == expected_halved);
        }

        TEST_CASE("Mat4x4 compound matrix multiplication vector multiplication and nearly equal") {
            Mat4x4 const value = {
                { 1.0F,  2.0F,  3.0F,  4.0F},
                { 5.0F,  6.0F,  7.0F,  8.0F},
                { 9.0F, 10.0F, 11.0F, 12.0F},
                {13.0F, 14.0F, 15.0F, 16.0F},
            };
            Mat4x4 const ones = {
                {1.0F, 1.0F, 1.0F, 1.0F},
                {1.0F, 1.0F, 1.0F, 1.0F},
                {1.0F, 1.0F, 1.0F, 1.0F},
                {1.0F, 1.0F, 1.0F, 1.0F},
            };
            Mat4x4       changed          = value;
            Mat4x4 const expected_product = {
                {10.0F, 10.0F, 10.0F, 10.0F},
                {26.0F, 26.0F, 26.0F, 26.0F},
                {42.0F, 42.0F, 42.0F, 42.0F},
                {58.0F, 58.0F, 58.0F, 58.0F},
            };

            changed += ones;
            CHECK(changed == value + ones);

            changed -= ones;
            CHECK(changed == value);

            changed *= 2.0F;
            CHECK(changed == value * 2.0F);

            changed /= 2.0F;
            CHECK(changed == value);

            CHECK(value * ones == expected_product);
            CHECK(value * Vec4{1.0F, 1.0F, 1.0F, 1.0F} == Vec4{10.0F, 26.0F, 42.0F, 58.0F});

            Mat4x4d near = Mat4x4d::identity();
            near(0, 3)   = 0.5 * kEpsilonV<f64>;
            CHECK(isNearlyEqual(near, Mat4x4d::identity()));

            near(0, 3) = 2.0 * kEpsilonV<f64>;
            CHECK_FALSE(isNearlyEqual(near, Mat4x4d::identity()));
        }

    } // namespace
} // namespace epsilon::math
