#ifndef EPSILON_MATH_SCALAR_SCALAR_HPP
#define EPSILON_MATH_SCALAR_SCALAR_HPP

#include "epsilon-math01/scalar/concepts.hpp"
#include "epsilon-math01/types.hpp"

namespace epsilon::math {

    template<ScalarLike T>
    inline constexpr T kPiV = static_cast<T>(3.14159265358979323846264338327950288L);

    template<ScalarLike T>
    inline constexpr T kTwoPiV = T{2} * kPiV<T>;

    template<ScalarLike T>
    inline constexpr T kHalfPiV = T{0.5} * kPiV<T>;

    template<ScalarLike T>
    inline constexpr T kDegToRadV = kPiV<T> / T{180};

    template<ScalarLike T>
    inline constexpr T kRadToDegV = T{180} / kPiV<T>;

    template<ScalarLike T>
    inline constexpr T kEpsilonV = static_cast<T>(0);

    template<>
    inline constexpr f32 kEpsilonV<f32> = 1.0e-6F;

    template<>
    inline constexpr f64 kEpsilonV<f64> = 1.0e-12;

    inline constexpr Scalar kPi       = kPiV<Scalar>;
    inline constexpr Scalar kTwoPi    = kTwoPiV<Scalar>;
    inline constexpr Scalar kHalfPi   = kHalfPiV<Scalar>;
    inline constexpr Scalar kDegToRad = kDegToRadV<Scalar>;
    inline constexpr Scalar kRadToDeg = kRadToDegV<Scalar>;
    inline constexpr Scalar kEpsilon  = kEpsilonV<Scalar>;

    template<ScalarLike T>
    [[nodiscard]] constexpr T abs(T value) noexcept {
        return value < T{0} ? -value : value;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T minimum(T lhs, T rhs) noexcept {
        return lhs < rhs ? lhs : rhs;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T maximum(T lhs, T rhs) noexcept {
        return lhs > rhs ? lhs : rhs;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T clamp(T value, T lower_bound, T upper_bound) noexcept {
        return minimum(maximum(value, lower_bound), upper_bound);
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T saturate(T value) noexcept {
        return clamp(value, T{0}, T{1});
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T square(T value) noexcept {
        return value * value;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T lerp(T start, T end, T t) noexcept {
        return start + (end - start) * t;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T radians(T degrees) noexcept {
        return degrees * kDegToRadV<T>;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T degrees(T radians) noexcept {
        return radians * kRadToDegV<T>;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr bool isNearlyZero(T value, T epsilon = kEpsilonV<T>) noexcept {
        return abs(value) <= epsilon;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr bool isNearlyEqual(T lhs, T rhs, T epsilon = kEpsilonV<T>) noexcept {
        return isNearlyZero(lhs - rhs, epsilon);
    }

} // namespace epsilon::math

#endif // EPSILON_MATH_SCALAR_SCALAR_HPP
