#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/matrix.hpp>
#include <type_traits>

namespace epsilon::math {
    namespace {

        template<class MatrixT>
        concept HasMatrixDimension = requires {
            MatrixT::kDimension;
        };

        TEST_CASE("mat aggregate header exposes common matrix types") {
            CHECK(Mat2x2::identity() * Vec2{2.0F, 3.0F} == Vec2{2.0F, 3.0F});
            CHECK(Mat3x3::identity() * Vec3{2.0F, 3.0F, 4.0F} == Vec3{2.0F, 3.0F, 4.0F});
            CHECK(Mat4x4::identity() * Vec4{2.0F, 3.0F, 4.0F, 5.0F} == Vec4{2.0F, 3.0F, 4.0F, 5.0F});

            static_assert(Mat2x2::kRows == 2);
            static_assert(Mat2x2::kCols == 2);
            static_assert(Mat2x2::kDimension == 2);
            static_assert(Mat2x2::kElementCount == 4);
            static_assert(Mat2x3::kRows == 2);
            static_assert(Mat2x3::kCols == 3);
            static_assert(Mat2x3::kElementCount == 6);
            static_assert(!HasMatrixDimension<Mat2x3>);
            static_assert(std::is_same_v<Mat2x2, Mat2x2f>);
            static_assert(std::is_same_v<Mat2x3, Mat2x3f>);
            static_assert(std::is_same_v<Mat2x4, Mat2x4f>);
            static_assert(std::is_same_v<Mat3x2, Mat3x2f>);
            static_assert(std::is_same_v<Mat3x3, Mat3x3f>);
            static_assert(std::is_same_v<Mat3x4, Mat3x4f>);
            static_assert(std::is_same_v<Mat4x2, Mat4x2f>);
            static_assert(std::is_same_v<Mat4x3, Mat4x3f>);
            static_assert(std::is_same_v<Mat4x4, Mat4x4f>);
            static_assert(sizeof(Mat2x3d) == sizeof(f64) * 6);
            static_assert(sizeof(Mat4x4d) == sizeof(f64) * 16);
        }

        TEST_CASE("specialized mat2x2 exposes row major members and identity") {
            Mat2x2 value{};
            value.m00() = 1.0F;
            value.m01() = 2.0F;
            value.m10() = 3.0F;
            value.m11() = 4.0F;

            CHECK(value(0, 0) == 1.0F);
            CHECK(value(0, 1) == 2.0F);
            CHECK(value(1, 0) == 3.0F);
            CHECK(value(1, 1) == 4.0F);
            CHECK(value.raw()[0] == value.m00());
            CHECK(value.raw()[1] == value.m01());
            CHECK(value.raw()[2] == value.m10());
            CHECK(value.raw()[3] == value.m11());
            CHECK(&value.raw()[0] == &value.m00());
            CHECK(&value.raw()[1] == &value.m01());
            CHECK(&value.raw()[2] == &value.m10());
            CHECK(&value.raw()[3] == &value.m11());
            CHECK(&value.a() == &value.m00());
            CHECK(&value.b() == &value.m01());
            CHECK(&value.c() == &value.m10());
            CHECK(&value.d() == &value.m11());
            CHECK(&value[1][1] == &value.m11());

            Mat2x2 const expected_identity = {
                {1.0F, 0.0F},
                {0.0F, 1.0F},
            };
            CHECK(Mat2x2::identity() == expected_identity);
            CHECK(Mat3x3::identity() * Vec3{2.0F, 3.0F, 4.0F} == Vec3{2.0F, 3.0F, 4.0F});
            CHECK(Mat4x4::identity() * Vec4{2.0F, 3.0F, 4.0F, 5.0F} == Vec4{2.0F, 3.0F, 4.0F, 5.0F});
        }

        TEST_CASE("rectangular matrices support construction storage and transpose") {
            Mat2x3 value{};
            value(0, 0) = 1.0F;
            value(0, 1) = 2.0F;
            value(0, 2) = 3.0F;
            value(1, 0) = 4.0F;
            value(1, 1) = 5.0F;
            value[1][2] = 6.0F;

            Scalar const *flat = value.raw();
            CHECK(flat[0] == 1.0F);
            CHECK(flat[1] == 2.0F);
            CHECK(flat[2] == 3.0F);
            CHECK(flat[3] == 4.0F);
            CHECK(flat[4] == 5.0F);
            CHECK(flat[5] == 6.0F);
            CHECK(&value[1][2] == &value(1, 2));
            CHECK(&value.raw()[0] == &value.m00());
            CHECK(&value.raw()[1] == &value.m01());
            CHECK(&value.raw()[2] == &value.m02());
            CHECK(&value.raw()[3] == &value.m10());
            CHECK(&value.raw()[4] == &value.m11());
            CHECK(&value.raw()[5] == &value.m12());

            Mat2x3 const flat_init = {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F};
            Mat2x3 const row_init  = {
                {1.0F, 2.0F, 3.0F},
                {4.0F, 5.0F, 6.0F},
            };
            Mat2x3 const partial = {
                {1.0F, 2.0F},
                {4.0F},
            };
            Mat2x3 const expected_partial = {
                {1.0F, 2.0F, 0.0F},
                {4.0F, 0.0F, 0.0F},
            };
            Mat3x2 const expected_transpose = {
                {1.0F, 4.0F},
                {2.0F, 5.0F},
                {3.0F, 6.0F},
            };

            static_assert(std::is_same_v<decltype(transpose(value)), Mat3x2>);
            CHECK(Mat2x3::zero() == Mat2x3{});
            CHECK(flat_init == value);
            CHECK(row_init == value);
            CHECK(partial == expected_partial);
            CHECK(transpose(value) == expected_transpose);

            Mat3x2 const extra          = {1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F};
            Mat3x2 const expected_extra = {
                {1.0F, 2.0F},
                {3.0F, 4.0F},
                {5.0F, 6.0F},
            };
            CHECK(extra == expected_extra);

            Mat4x4 const partial_square = {
                {1.0F, 2.0F},
                {3.0F},
            };
            Mat4x4 const expected_partial_square = {
                {1.0F, 2.0F, 0.0F, 0.0F},
                {3.0F, 0.0F, 0.0F, 0.0F},
                {0.0F, 0.0F, 0.0F, 0.0F},
                {0.0F, 0.0F, 0.0F, 0.0F},
            };
            CHECK(partial_square == expected_partial_square);
        }

        TEST_CASE("rectangular matrices support arithmetic multiplication and comparison") {
            Mat2x3 const value = {
                {1.0F, 2.0F, 3.0F},
                {4.0F, 5.0F, 6.0F},
            };
            Mat2x3 const other = {
                { 7.0F,  8.0F,  9.0F},
                {10.0F, 11.0F, 12.0F},
            };
            Mat<Scalar, 3, 4> const rhs = {
                {1.0F,  2.0F,  3.0F,  4.0F},
                {5.0F,  6.0F,  7.0F,  8.0F},
                {9.0F, 10.0F, 11.0F, 12.0F},
            };
            Mat2x3 changed = value;

            Mat2x3 const expected_sum = {
                { 8.0F, 10.0F, 12.0F},
                {14.0F, 16.0F, 18.0F},
            };
            Mat2x3 const expected_difference = {
                {6.0F, 6.0F, 6.0F},
                {6.0F, 6.0F, 6.0F},
            };
            Mat2x3 const expected_negated = {
                {-1.0F, -2.0F, -3.0F},
                {-4.0F, -5.0F, -6.0F},
            };
            Mat2x3 const expected_scaled = {
                {2.0F,  4.0F,  6.0F},
                {8.0F, 10.0F, 12.0F},
            };
            Mat2x3 const expected_halved = {
                {0.5F, 1.0F, 1.5F},
                {2.0F, 2.5F, 3.0F},
            };
            Mat<Scalar, 2, 4> const expected_product = {
                {38.0F, 44.0F,  50.0F,  56.0F},
                {83.0F, 98.0F, 113.0F, 128.0F},
            };

            static_assert(std::is_same_v<decltype(value * rhs), Mat<Scalar, 2, 4>>);
            static_assert(std::is_same_v<decltype(value * Vec3{}), Vec2>);
            CHECK(value + other == expected_sum);
            CHECK(other - value == expected_difference);
            CHECK(-value == expected_negated);
            CHECK(value * 2.0F == expected_scaled);
            CHECK(2.0F * value == expected_scaled);
            CHECK(value / 2.0F == expected_halved);
            CHECK(value * rhs == expected_product);
            CHECK(value * Vec3{7.0F, 8.0F, 9.0F} == Vec2{50.0F, 122.0F});

            changed += other;
            CHECK(changed == expected_sum);
            changed -= other;
            CHECK(changed == value);
            changed *= 2.0F;
            CHECK(changed == expected_scaled);
            changed /= 2.0F;
            CHECK(changed == value);

            Mat2x3 near = value;
            near(1, 2) += 0.5F * kEpsilon;
            CHECK(isNearlyEqual(near, value));
            near(1, 2) += 2.0F * kEpsilon;
            CHECK_FALSE(isNearlyEqual(near, value));
        }

    } // namespace
} // namespace epsilon::math
