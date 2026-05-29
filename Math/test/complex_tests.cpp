#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/complex.hpp>

#include <cmath>

namespace epsilon::math {
    namespace {

        TEST_CASE("complex aliases and default construction") {
            CHECK(sizeof(Complex) == sizeof(Complexf));
            CHECK(sizeof(Complexd) == sizeof(f64) * 2);
            CHECK(Complex{} == Complex::zero());
            CHECK(Complex::one() == Complex{1.0F, 0.0F});
            CHECK(Complex::i() == Complex{0.0F, 1.0F});
        }

        TEST_CASE("complex stores components in real imag order") {
            Complex value{1.0F, 2.0F};

            CHECK(value(0) == 1.0F);
            CHECK(value(1) == 2.0F);
            CHECK(value[0] == 1.0F);
            CHECK(value[1] == 2.0F);

            value(0) = 3.0F;
            value[1] = 4.0F;
            CHECK(value == Complex{3.0F, 4.0F});

            Complex const const_value = value;
            CHECK(const_value(0) == 3.0F);
            CHECK(const_value[1] == 4.0F);
        }

        TEST_CASE("complex arithmetic works") {
            Complex const lhs{1.0F, 2.0F};
            Complex const rhs{3.0F, 4.0F};
            Complex       value = lhs;

            CHECK(lhs + rhs == Complex{4.0F, 6.0F});
            CHECK(rhs - lhs == Complex{2.0F, 2.0F});
            CHECK(-lhs == Complex{-1.0F, -2.0F});
            CHECK(lhs * 2.0F == Complex{2.0F, 4.0F});
            CHECK(2.0F * lhs == Complex{2.0F, 4.0F});
            CHECK(lhs / 2.0F == Complex{0.5F, 1.0F});
            CHECK(lhs * rhs == Complex{-5.0F, 10.0F});
            CHECK(isNearlyEqual(lhs / rhs, Complex{11.0F / 25.0F, 2.0F / 25.0F}));

            value += rhs;
            CHECK(value == Complex{4.0F, 6.0F});

            value -= rhs;
            CHECK(value == lhs);

            value *= 2.0F;
            CHECK(value == Complex{2.0F, 4.0F});

            value /= 2.0F;
            CHECK(value == lhs);

            value *= rhs;
            CHECK(value == Complex{-5.0F, 10.0F});
        }

        TEST_CASE("complex modulus conjugate inverse and comparison work") {
            Complex const value{3.0F, 4.0F};

            CHECK(modulusSquared(value) == 25.0F);
            CHECK(modulus(value) == 5.0F);
            CHECK(normalized(Complex::zero()) == Complex::zero());
            CHECK(inverse(Complex::zero()) == Complex::zero());
            CHECK(conjugate(value) == Complex{3.0F, -4.0F});
            CHECK(isNearlyEqual(value * inverse(value), Complex::one()));

            Complex near = Complex::one();
            near.imag    = 0.5F * kEpsilon;
            CHECK(isNearlyEqual(near, Complex::one()));

            near.imag = 2.0F * kEpsilon;
            CHECK_FALSE(isNearlyEqual(near, Complex::one()));
        }

        TEST_CASE("complex polar coordinates and vec2 rotation work") {
            Complex const quarter_turn = fromPolar(1.0F, kHalfPi);
            Vec2 const    x_axis{1.0F, 0.0F};
            Vec2 const    vector{3.0F, 4.0F};

            CHECK(isNearlyEqual(quarter_turn, Complex{0.0F, 1.0F}));
            CHECK(isNearlyEqual(arg(quarter_turn), kHalfPi));
            CHECK(toVec2(fromVec2(vector)) == vector);
            CHECK(isNearlyEqual(rotate(quarter_turn, x_axis), Vec2{0.0F, 1.0F}));
            CHECK(rotate(Complex::zero(), vector) == vector);
        }

    } // namespace
} // namespace epsilon::math
