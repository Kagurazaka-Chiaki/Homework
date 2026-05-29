#ifndef EPSILON_MATH_COMPLEX_COMPLEX_HPP
#define EPSILON_MATH_COMPLEX_COMPLEX_HPP

#include "epsilon-math01/scalar/scalar.hpp"
#include "epsilon-math01/vector.hpp"

#include <cassert>
#include <cmath>
#include <cstddef>
#include <utility>

namespace epsilon::math {

    template<ScalarLike T>
    struct ComplexT {
        using ValueType = T;

        T real = T{0};
        T imag = T{0};

        constexpr ComplexT() noexcept = default;

        constexpr ComplexT(T real_value, T imag_value) noexcept
            : real(real_value)
            , imag(imag_value) {
        }

        [[nodiscard]] constexpr T &operator()(std::size_t index) noexcept {
            assert(index < 2);
            switch (index) {
                case 0:
                    return real;
                case 1:
                    return imag;
                default:
                    std::unreachable();
            }
        }

        [[nodiscard]] constexpr T const &operator()(std::size_t index) const noexcept {
            assert(index < 2);
            switch (index) {
                case 0:
                    return real;
                case 1:
                    return imag;
                default:
                    std::unreachable();
            }
        }

        [[nodiscard]] constexpr T &operator[](std::size_t index) noexcept {
            return (*this)(index);
        }

        [[nodiscard]] constexpr T const &operator[](std::size_t index) const noexcept {
            return (*this)(index);
        }

        [[nodiscard]] static constexpr ComplexT zero() noexcept {
            return {};
        }

        [[nodiscard]] static constexpr ComplexT one() noexcept {
            return {T{1}, T{0}};
        }

        [[nodiscard]] static constexpr ComplexT i() noexcept {
            return {T{0}, T{1}};
        }

        [[nodiscard]] constexpr bool operator==(ComplexT const &) const noexcept = default;
    };

    using Complex  = ComplexT<Scalar>;
    using Complexf = ComplexT<f32>;
    using Complexd = ComplexT<f64>;

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> operator+(ComplexT<T> lhs, ComplexT<T> rhs) noexcept {
        return {
            lhs.real + rhs.real,
            lhs.imag + rhs.imag,
        };
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> operator-(ComplexT<T> lhs, ComplexT<T> rhs) noexcept {
        return {
            lhs.real - rhs.real,
            lhs.imag - rhs.imag,
        };
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> operator-(ComplexT<T> value) noexcept {
        return {-value.real, -value.imag};
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> operator*(ComplexT<T> value, T scalar) noexcept {
        return {
            value.real * scalar,
            value.imag * scalar,
        };
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> operator*(T scalar, ComplexT<T> value) noexcept {
        return value * scalar;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> operator/(ComplexT<T> value, T scalar) noexcept {
        return {
            value.real / scalar,
            value.imag / scalar,
        };
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> operator*(ComplexT<T> lhs, ComplexT<T> rhs) noexcept {
        return {
            lhs.real * rhs.real - lhs.imag * rhs.imag,
            lhs.real * rhs.imag + lhs.imag * rhs.real,
        };
    }

    template<ScalarLike T>
    constexpr ComplexT<T> &operator+=(ComplexT<T> &lhs, ComplexT<T> rhs) noexcept {
        lhs = lhs + rhs;
        return lhs;
    }

    template<ScalarLike T>
    constexpr ComplexT<T> &operator-=(ComplexT<T> &lhs, ComplexT<T> rhs) noexcept {
        lhs = lhs - rhs;
        return lhs;
    }

    template<ScalarLike T>
    constexpr ComplexT<T> &operator*=(ComplexT<T> &value, T scalar) noexcept {
        value = value * scalar;
        return value;
    }

    template<ScalarLike T>
    constexpr ComplexT<T> &operator/=(ComplexT<T> &value, T scalar) noexcept {
        value = value / scalar;
        return value;
    }

    template<ScalarLike T>
    constexpr ComplexT<T> &operator*=(ComplexT<T> &lhs, ComplexT<T> rhs) noexcept {
        lhs = lhs * rhs;
        return lhs;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T modulusSquared(ComplexT<T> value) noexcept {
        return value.real * value.real + value.imag * value.imag;
    }

    template<ScalarLike T>
    [[nodiscard]] T modulus(ComplexT<T> value) noexcept {
        return std::sqrt(modulusSquared(value));
    }

    template<ScalarLike T>
    [[nodiscard]] ComplexT<T> normalized(ComplexT<T> value, T epsilon = kEpsilonV<T>) noexcept {
        T const value_modulus = modulus(value);
        return isNearlyZero(value_modulus, epsilon) ? ComplexT<T>::zero() : value / value_modulus;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> conjugate(ComplexT<T> value) noexcept {
        return {value.real, -value.imag};
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> inverse(ComplexT<T> value, T epsilon = kEpsilonV<T>) noexcept {
        T const value_modulus_squared = modulusSquared(value);
        return isNearlyZero(value_modulus_squared, epsilon) ? ComplexT<T>::zero() : conjugate(value) / value_modulus_squared;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> operator/(ComplexT<T> lhs, ComplexT<T> rhs) noexcept {
        return lhs * inverse(rhs);
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr bool isNearlyEqual(ComplexT<T> lhs, ComplexT<T> rhs, T epsilon = kEpsilonV<T>) noexcept {
        return isNearlyEqual(lhs.real, rhs.real, epsilon) && isNearlyEqual(lhs.imag, rhs.imag, epsilon);
    }

    template<ScalarLike T>
    [[nodiscard]] ComplexT<T> fromPolar(T radius, T radians) noexcept {
        return {
            radius * std::cos(radians),
            radius * std::sin(radians),
        };
    }

    template<ScalarLike T>
    [[nodiscard]] T arg(ComplexT<T> value) noexcept {
        return std::atan2(value.imag, value.real);
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr ComplexT<T> fromVec2(Vec<T, 2> vector) noexcept {
        return {vector.x, vector.y};
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr Vec<T, 2> toVec2(ComplexT<T> value) noexcept {
        return {value.real, value.imag};
    }

    template<ScalarLike T>
    [[nodiscard]] Vec<T, 2> rotate(ComplexT<T> rotation, Vec<T, 2> vector) noexcept {
        T const rotation_modulus = modulus(rotation);
        if (isNearlyZero(rotation_modulus)) {
            return vector;
        }

        ComplexT<T> const unit   = rotation / rotation_modulus;
        ComplexT<T> const result = unit * fromVec2(vector);
        return toVec2(result);
    }

} // namespace epsilon::math

#endif // EPSILON_MATH_COMPLEX_COMPLEX_HPP
