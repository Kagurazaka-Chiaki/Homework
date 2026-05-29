#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/vector.hpp>

#include <cmath>

namespace epsilon::math {
    namespace {

        TEST_CASE("vec aliases use the requested scalar and dimension") {
            CHECK(sizeof(Vec<float, 5>) == sizeof(float) * 5);
            CHECK(sizeof(Vec<double, 5>) == sizeof(double) * 5);
            CHECK(sizeof(Vec<int, 5>) == sizeof(int) * 5);
            CHECK(Vec<float, 5>::kDimension == 5);
            CHECK(Vec<double, 5>::kDimension == 5);
            CHECK(Vec<int, 5>::kDimension == 5);
            CHECK(sizeof(Vec2i) == sizeof(i32) * 2);
            CHECK(sizeof(Vec3i) == sizeof(i32) * 3);
            CHECK(sizeof(Vec4i) == sizeof(i32) * 4);
        }

        TEST_CASE("vec initializer list fills truncates and zero initializes") {
            Vec<float, 5> const default_value{};
            CHECK(default_value == Vec<float, 5>{0.0F, 0.0F, 0.0F, 0.0F, 0.0F});

            Vec<float, 5> const partial{1.0F, 2.0F};
            CHECK(partial == Vec<float, 5>{1.0F, 2.0F, 0.0F, 0.0F, 0.0F});

            Vec<float, 3> const truncated{1.0F, 2.0F, 3.0F, 4.0F};
            CHECK(truncated == Vec<float, 3>{1.0F, 2.0F, 3.0F});
        }

        TEST_CASE("vec supports indexed component access") {
            Vec<float, 5> value{1.0F, 2.0F, 3.0F, 4.0F, 5.0F};

            CHECK(value(0) == 1.0F);
            CHECK(value(4) == 5.0F);
            CHECK(value[0] == 1.0F);
            CHECK(value[4] == 5.0F);

            value(0) = 6.0F;
            value[4] = 10.0F;
            CHECK(value == Vec<float, 5>{6.0F, 2.0F, 3.0F, 4.0F, 10.0F});

            Vec<float, 5> const const_value = value;
            CHECK(const_value(0) == 6.0F);
            CHECK(const_value[4] == 10.0F);
        }

        TEST_CASE("vec float arithmetic works component-wise") {
            Vec<float, 5> const original{1.0F, 2.0F, 3.0F, 4.0F, 5.0F};
            Vec<float, 5>       value = original;

            CHECK(value + Vec<float, 5>{5.0F, 4.0F, 3.0F, 2.0F, 1.0F} == Vec<float, 5>{6.0F, 6.0F, 6.0F, 6.0F, 6.0F});
            CHECK(value - Vec<float, 5>{0.5F, 1.0F, 1.5F, 2.0F, 2.5F} == Vec<float, 5>{0.5F, 1.0F, 1.5F, 2.0F, 2.5F});
            CHECK(-value == Vec<float, 5>{-1.0F, -2.0F, -3.0F, -4.0F, -5.0F});
            CHECK(value == original);
            CHECK(value * 2.0F == Vec<float, 5>{2.0F, 4.0F, 6.0F, 8.0F, 10.0F});
            CHECK(2.0F * value == Vec<float, 5>{2.0F, 4.0F, 6.0F, 8.0F, 10.0F});
            CHECK(value / 2.0F == Vec<float, 5>{0.5F, 1.0F, 1.5F, 2.0F, 2.5F});

            value += Vec<float, 5>{1.0F, 1.0F, 1.0F, 1.0F, 1.0F};
            CHECK(value == Vec<float, 5>{2.0F, 3.0F, 4.0F, 5.0F, 6.0F});

            value -= Vec<float, 5>{1.0F, 1.0F, 1.0F, 1.0F, 1.0F};
            CHECK(value == original);

            value *= 2.0F;
            CHECK(value == Vec<float, 5>{2.0F, 4.0F, 6.0F, 8.0F, 10.0F});

            value /= 2.0F;
            CHECK(value == original);
        }

        TEST_CASE("vec int arithmetic and dot work") {
            Vec<int, 5> const lhs{1, 2, 3, 4, 5};
            Vec<int, 5>       value = lhs;

            CHECK(value + Vec<int, 5>{5, 4, 3, 2, 1} == Vec<int, 5>{6, 6, 6, 6, 6});
            CHECK(value - Vec<int, 5>{1, 1, 1, 1, 1} == Vec<int, 5>{0, 1, 2, 3, 4});
            CHECK(-value == Vec<int, 5>{-1, -2, -3, -4, -5});
            CHECK(value * 2 == Vec<int, 5>{2, 4, 6, 8, 10});
            CHECK(2 * value == Vec<int, 5>{2, 4, 6, 8, 10});
            CHECK(value / 2 == Vec<int, 5>{0, 1, 1, 2, 2});
            CHECK(dot(lhs, Vec<int, 5>{5, 4, 3, 2, 1}) == 35);

            value += Vec<int, 5>{1, 1, 1, 1, 1};
            CHECK(value == Vec<int, 5>{2, 3, 4, 5, 6});

            value -= Vec<int, 5>{1, 1, 1, 1, 1};
            CHECK(value == lhs);

            value *= 2;
            CHECK(value == Vec<int, 5>{2, 4, 6, 8, 10});

            value /= 2;
            CHECK(value == lhs);
        }

        TEST_CASE("vec floating length normalization and comparison work") {
            CHECK(dot(Vec<float, 5>{1.0F, 2.0F, 3.0F, 4.0F, 5.0F}, Vec<float, 5>{5.0F, 4.0F, 3.0F, 2.0F, 1.0F}) == 35.0F);
            CHECK(normSquared(Vec<float, 5>{1.0F, 2.0F, 2.0F, 4.0F, 4.0F}) == 41.0F);
            CHECK(isNearlyEqual(length(Vec<float, 5>{1.0F, 2.0F, 2.0F, 4.0F, 4.0F}), std::sqrt(41.0F)));
            CHECK(normalized(Vec<float, 5>{}) == Vec<float, 5>{});
            CHECK(isNearlyEqual(normalized(Vec<float, 5>{0.0F, 0.0F, 0.0F, 0.0F, 5.0F}), Vec<float, 5>{0.0F, 0.0F, 0.0F, 0.0F, 1.0F}));
        }

        TEST_CASE("vec floating norm supports common orders") {
            Vec<float, 5> const value{-1.0F, 2.0F, -2.0F, 4.0F, -4.0F};

            CHECK(norm(value, 0) == 4.0F);
            CHECK(norm(value, 1) == 13.0F);
            CHECK(isNearlyEqual(norm(value, 2), std::sqrt(41.0F)));
            CHECK(isNearlyEqual(norm(value, 3), std::cbrt(145.0F)));
            CHECK(isNearlyEqual(norm(value, 4), std::pow(545.0F, 0.25F)));
            CHECK(norm(value, -1) == 0.0F);
        }

    } // namespace
} // namespace epsilon::math
