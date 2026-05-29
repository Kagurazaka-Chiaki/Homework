#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/axis.hpp>

namespace epsilon::math {
    namespace {

        TEST_CASE("AxisDirection2 defaults to positive X") {
            AxisDirection2 const direction{};

            CHECK(direction.axis == Axis2::X);
            CHECK(direction.sign == Sign::Positive);
        }

        TEST_CASE("AxisDirection3 defaults to positive X") {
            AxisDirection3 const direction{};

            CHECK(direction.axis == Axis3::X);
            CHECK(direction.sign == Sign::Positive);
        }

        TEST_CASE("Axis directions support equality") {
            CHECK(AxisDirection2{Axis2::Y, Sign::Negative} == AxisDirection2{Axis2::Y, Sign::Negative});
            CHECK(AxisDirection3{Axis3::Z, Sign::Positive} == AxisDirection3{Axis3::Z, Sign::Positive});
        }

        TEST_CASE("AxisDirection3 can represent negative Z") {
            AxisDirection3 const direction{Axis3::Z, Sign::Negative};

            CHECK(direction.axis == Axis3::Z);
            CHECK(direction.sign == Sign::Negative);
        }

    } // namespace
} // namespace epsilon::math
