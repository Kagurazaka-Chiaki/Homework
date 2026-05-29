#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/vector.hpp>

#include <cmath>

namespace epsilon::math {
    namespace {

        TEST_CASE("vec3 aliases use the default scalar type") {
            CHECK(sizeof(Vec3) == sizeof(Vec3f));
            CHECK(sizeof(Vec3d) == sizeof(f64) * 3);
        }

        TEST_CASE("vec3 supports indexed component access") {
            Vec3 value{1.0F, 2.0F, 3.0F};

            CHECK(value(0) == 1.0F);
            CHECK(value(1) == 2.0F);
            CHECK(value(2) == 3.0F);
            CHECK(value[0] == 1.0F);
            CHECK(value[1] == 2.0F);
            CHECK(value[2] == 3.0F);

            value(0) = 4.0F;
            value[1] = 5.0F;
            value(2) = 6.0F;
            CHECK(value == Vec3{4.0F, 5.0F, 6.0F});

            Vec3 const const_value = value;
            CHECK(const_value(0) == 4.0F);
            CHECK(const_value[1] == 5.0F);
            CHECK(const_value(2) == 6.0F);
        }

        TEST_CASE("vec3 arithmetic works component-wise") {
            Vec3 const original{1.0F, 2.0F, 3.0F};
            Vec3       value = original;

            CHECK(value + Vec3{4.0F, 5.0F, 6.0F} == Vec3{5.0F, 7.0F, 9.0F});
            CHECK(value - Vec3{0.5F, 1.0F, 1.5F} == Vec3{0.5F, 1.0F, 1.5F});
            CHECK(-value == Vec3{-1.0F, -2.0F, -3.0F});
            CHECK(value == original);
            CHECK(value * 2.0F == Vec3{2.0F, 4.0F, 6.0F});
            CHECK(2.0F * value == Vec3{2.0F, 4.0F, 6.0F});
            CHECK(value / 2.0F == Vec3{0.5F, 1.0F, 1.5F});

            value += Vec3{1.0F, 1.0F, 1.0F};
            CHECK(value == Vec3{2.0F, 3.0F, 4.0F});

            value -= Vec3{1.0F, 1.0F, 1.0F};
            CHECK(value == original);

            value *= 2.0F;
            CHECK(value == Vec3{2.0F, 4.0F, 6.0F});

            value /= 2.0F;
            CHECK(value == original);
        }

        TEST_CASE("vec3 dot cross length normalization and comparison work") {
            CHECK(dot(Vec3{1.0F, 2.0F, 3.0F}, Vec3{4.0F, 5.0F, 6.0F}) == 32.0F);
            CHECK(cross(Vec3{1.0F, 0.0F, 0.0F}, Vec3{0.0F, 1.0F, 0.0F}) == Vec3{0.0F, 0.0F, 1.0F});
            CHECK(normSquared(Vec3{2.0F, 3.0F, 6.0F}) == 49.0F);
            CHECK(isNearlyEqual(length(Vec3{2.0F, 3.0F, 6.0F}), 7.0F));
            CHECK(normalized(Vec3{}) == Vec3{});

            Vec3 const unit_x = normalized(Vec3{4.0F, 0.0F, 0.0F});
            CHECK(isNearlyEqual(unit_x, Vec3{1.0F, 0.0F, 0.0F}));
            CHECK(isNearlyEqual(length(unit_x), 1.0F));
        }

        TEST_CASE("vec3 norm supports common orders") {
            Vec3 const value{-2.0F, 3.0F, 6.0F};

            CHECK(norm(value, 0) == 6.0F);
            CHECK(norm(value, 1) == 11.0F);
            CHECK(isNearlyEqual(norm(value, 2), 7.0F));
            CHECK(isNearlyEqual(norm(value, 3), std::cbrt(251.0F)));
            CHECK(isNearlyEqual(norm(value, 4), std::pow(1393.0F, 0.25F)));
            CHECK(norm(value, -1) == 0.0F);
        }

    } // namespace
} // namespace epsilon::math
