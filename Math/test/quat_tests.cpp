#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/quaternion.hpp>

#include <cmath>

namespace epsilon::math {
    namespace {

        TEST_CASE("quat aliases and default construction") {
            CHECK(sizeof(Quat) == sizeof(Quatf));
            CHECK(sizeof(Quatd) == sizeof(f64) * 4);
            CHECK(Quat{} == Quat::identity());
            CHECK(Quat::zero() == Quat{0.0F, 0.0F, 0.0F, 0.0F});
        }

        TEST_CASE("quat stores components in w x y z order") {
            Quat value{1.0F, 2.0F, 3.0F, 4.0F};

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
            CHECK(value == Quat{5.0F, 6.0F, 7.0F, 8.0F});

            Quat const const_value = value;
            CHECK(const_value(0) == 5.0F);
            CHECK(const_value[1] == 6.0F);
            CHECK(const_value(2) == 7.0F);
            CHECK(const_value[3] == 8.0F);
        }

        TEST_CASE("quat arithmetic and Hamilton product work") {
            Quat const lhs{1.0F, 2.0F, 3.0F, 4.0F};
            Quat const rhs{5.0F, 6.0F, 7.0F, 8.0F};
            Quat       value = lhs;

            CHECK(lhs + rhs == Quat{6.0F, 8.0F, 10.0F, 12.0F});
            CHECK(rhs - lhs == Quat{4.0F, 4.0F, 4.0F, 4.0F});
            CHECK(-lhs == Quat{-1.0F, -2.0F, -3.0F, -4.0F});
            CHECK(lhs * 2.0F == Quat{2.0F, 4.0F, 6.0F, 8.0F});
            CHECK(2.0F * lhs == Quat{2.0F, 4.0F, 6.0F, 8.0F});
            CHECK(lhs / 2.0F == Quat{0.5F, 1.0F, 1.5F, 2.0F});
            CHECK(lhs * rhs == Quat{-60.0F, 12.0F, 30.0F, 24.0F});

            value += rhs;
            CHECK(value == Quat{6.0F, 8.0F, 10.0F, 12.0F});

            value -= rhs;
            CHECK(value == lhs);

            value *= 2.0F;
            CHECK(value == Quat{2.0F, 4.0F, 6.0F, 8.0F});

            value /= 2.0F;
            CHECK(value == lhs);

            value *= rhs;
            CHECK(value == Quat{-60.0F, 12.0F, 30.0F, 24.0F});
        }

        TEST_CASE("quat normalization conjugate inverse and comparison work") {
            Quat const value{1.0F, 2.0F, 3.0F, 4.0F};

            CHECK(dot(value, value) == 30.0F);
            CHECK(normSquared(value) == 30.0F);
            CHECK(isNearlyEqual(length(value), std::sqrt(30.0F)));
            CHECK(normalized(Quat::zero()) == Quat::identity());
            CHECK(conjugate(value) == Quat{1.0F, -2.0F, -3.0F, -4.0F});
            CHECK(isNearlyEqual(value * inverse(value), Quat::identity()));

            Quat near = Quat::identity();
            near.x    = 0.5F * kEpsilon;
            CHECK(isNearlyEqual(near, Quat::identity()));

            near.x = 2.0F * kEpsilon;
            CHECK_FALSE(isNearlyEqual(near, Quat::identity()));
        }

        TEST_CASE("quat axis angle and matrix rotation use right handed active rotation") {
            Quat const identity = Quat::identity();
            Vec3 const x_axis{1.0F, 0.0F, 0.0F};

            CHECK(rotate(identity, x_axis) == x_axis);
            CHECK(fromAxisAngle(Vec3{}, kHalfPi) == Quat::identity());

            Quat const quarter_turn = fromAxisAngle(Vec3{0.0F, 0.0F, 1.0F}, kHalfPi);
            Vec3 const rotated      = rotate(quarter_turn, x_axis);
            Vec3 const matrix_value = toMat3(quarter_turn) * x_axis;

            CHECK(isNearlyEqual(rotated, Vec3{0.0F, 1.0F, 0.0F}));
            CHECK(isNearlyEqual(matrix_value, Vec3{0.0F, 1.0F, 0.0F}));
            CHECK(isNearlyEqual(rotated, matrix_value));
        }

    } // namespace
} // namespace epsilon::math
