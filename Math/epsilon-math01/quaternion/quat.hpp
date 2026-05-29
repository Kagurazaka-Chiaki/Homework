#ifndef EPSILON_MATH_QUATERNION_QUAT_HPP
#define EPSILON_MATH_QUATERNION_QUAT_HPP

#include "epsilon-math01/matrix/mat.hpp"
#include "epsilon-math01/matrix/mat3x3.hpp"
#include "epsilon-math01/matrix/mat_ops.hpp"
#include "epsilon-math01/scalar/scalar.hpp"
#include "epsilon-math01/vector/vec3.hpp"
#include "epsilon-math01/vector/vec_ops.hpp"

#include <cassert>
#include <cmath>
#include <cstddef>
#include <utility>

namespace epsilon::math {

    template<ScalarLike T>
    struct QuatT {
        using ValueType = T;

        T w = T{1};
        T x = T{0};
        T y = T{0};
        T z = T{0};

        constexpr QuatT() noexcept = default;

        constexpr QuatT(T w_value, T x_value, T y_value, T z_value) noexcept
            : w(w_value)
            , x(x_value)
            , y(y_value)
            , z(z_value) {
        }

        [[nodiscard]] constexpr T &operator()(std::size_t index) noexcept {
            assert(index < 4);
            switch (index) {
                case 0:
                    return w;
                case 1:
                    return x;
                case 2:
                    return y;
                case 3:
                    return z;
                default:
                    std::unreachable();
            }
        }

        [[nodiscard]] constexpr T const &operator()(std::size_t index) const noexcept {
            assert(index < 4);
            switch (index) {
                case 0:
                    return w;
                case 1:
                    return x;
                case 2:
                    return y;
                case 3:
                    return z;
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

        [[nodiscard]] static constexpr QuatT zero() noexcept {
            return {T{0}, T{0}, T{0}, T{0}};
        }

        [[nodiscard]] static constexpr QuatT identity() noexcept {
            return {};
        }

        [[nodiscard]] constexpr bool operator==(QuatT const &) const noexcept = default;
    };

    using Quat  = QuatT<Scalar>;
    using Quatf = QuatT<f32>;
    using Quatd = QuatT<f64>;

    template<ScalarLike T>
    [[nodiscard]] constexpr QuatT<T> operator+(QuatT<T> lhs, QuatT<T> rhs) noexcept {
        return {
            lhs.w + rhs.w,
            lhs.x + rhs.x,
            lhs.y + rhs.y,
            lhs.z + rhs.z,
        };
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr QuatT<T> operator-(QuatT<T> lhs, QuatT<T> rhs) noexcept {
        return {
            lhs.w - rhs.w,
            lhs.x - rhs.x,
            lhs.y - rhs.y,
            lhs.z - rhs.z,
        };
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr QuatT<T> operator-(QuatT<T> value) noexcept {
        return {-value.w, -value.x, -value.y, -value.z};
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr QuatT<T> operator*(QuatT<T> value, T scalar) noexcept {
        return {
            value.w * scalar,
            value.x * scalar,
            value.y * scalar,
            value.z * scalar,
        };
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr QuatT<T> operator*(T scalar, QuatT<T> value) noexcept {
        return value * scalar;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr QuatT<T> operator/(QuatT<T> value, T scalar) noexcept {
        return {
            value.w / scalar,
            value.x / scalar,
            value.y / scalar,
            value.z / scalar,
        };
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr QuatT<T> operator*(QuatT<T> lhs, QuatT<T> rhs) noexcept {
        return {
            lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z,
            lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
            lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w,
        };
    }

    template<ScalarLike T>
    constexpr QuatT<T> &operator+=(QuatT<T> &lhs, QuatT<T> rhs) noexcept {
        lhs = lhs + rhs;
        return lhs;
    }

    template<ScalarLike T>
    constexpr QuatT<T> &operator-=(QuatT<T> &lhs, QuatT<T> rhs) noexcept {
        lhs = lhs - rhs;
        return lhs;
    }

    template<ScalarLike T>
    constexpr QuatT<T> &operator*=(QuatT<T> &value, T scalar) noexcept {
        value = value * scalar;
        return value;
    }

    template<ScalarLike T>
    constexpr QuatT<T> &operator/=(QuatT<T> &value, T scalar) noexcept {
        value = value / scalar;
        return value;
    }

    template<ScalarLike T>
    constexpr QuatT<T> &operator*=(QuatT<T> &lhs, QuatT<T> rhs) noexcept {
        lhs = lhs * rhs;
        return lhs;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T dot(QuatT<T> lhs, QuatT<T> rhs) noexcept {
        return lhs.w * rhs.w + lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr T normSquared(QuatT<T> value) noexcept {
        return dot(value, value);
    }

    template<ScalarLike T>
    [[nodiscard]] T length(QuatT<T> value) noexcept {
        return std::sqrt(normSquared(value));
    }

    template<ScalarLike T>
    [[nodiscard]] QuatT<T> normalized(QuatT<T> value, T epsilon = kEpsilonV<T>) noexcept {
        T const value_length = length(value);
        return isNearlyZero(value_length, epsilon) ? QuatT<T>::identity() : value / value_length;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr QuatT<T> conjugate(QuatT<T> value) noexcept {
        return {value.w, -value.x, -value.y, -value.z};
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr QuatT<T> inverse(QuatT<T> value, T epsilon = kEpsilonV<T>) noexcept {
        T const length_squared = normSquared(value);
        return isNearlyZero(length_squared, epsilon) ? QuatT<T>::identity() : conjugate(value) / length_squared;
    }

    template<ScalarLike T>
    [[nodiscard]] constexpr bool isNearlyEqual(QuatT<T> lhs, QuatT<T> rhs, T epsilon = kEpsilonV<T>) noexcept {
        return isNearlyEqual(lhs.w, rhs.w, epsilon) && isNearlyEqual(lhs.x, rhs.x, epsilon) && isNearlyEqual(lhs.y, rhs.y, epsilon) && isNearlyEqual(lhs.z, rhs.z, epsilon);
    }

    template<ScalarLike T>
    [[nodiscard]] QuatT<T> fromAxisAngle(Vec<T, 3> axis, T radians) noexcept {
        T const axis_length = length(axis);
        if (isNearlyZero(axis_length)) {
            return QuatT<T>::identity();
        }

        Vec<T, 3> const normalized_axis = axis / axis_length;
        T const         half_angle      = radians * T{0.5};
        T const         sin_half_angle  = std::sin(half_angle);
        return {
            std::cos(half_angle),
            normalized_axis.x * sin_half_angle,
            normalized_axis.y * sin_half_angle,
            normalized_axis.z * sin_half_angle,
        };
    }

    template<ScalarLike T>
    [[nodiscard]] Mat<T, 3> toMat3(QuatT<T> quat) noexcept {
        QuatT<T> const unit = normalized(quat);

        T const xx = unit.x * unit.x;
        T const yy = unit.y * unit.y;
        T const zz = unit.z * unit.z;
        T const xy = unit.x * unit.y;
        T const xz = unit.x * unit.z;
        T const yz = unit.y * unit.z;
        T const wx = unit.w * unit.x;
        T const wy = unit.w * unit.y;
        T const wz = unit.w * unit.z;

        return {
            {T{1} - T{2} * (yy + zz),        T{2} * (xy - wz),        T{2} * (xz + wy)},
            {       T{2} * (xy + wz), T{1} - T{2} * (xx + zz),        T{2} * (yz - wx)},
            {       T{2} * (xz - wy),        T{2} * (yz + wx), T{1} - T{2} * (xx + yy)},
        };
    }

    template<ScalarLike T>
    [[nodiscard]] Vec<T, 3> rotate(QuatT<T> quat, Vec<T, 3> vector) noexcept {
        return toMat3(quat) * vector;
    }

} // namespace epsilon::math

#endif // EPSILON_MATH_QUATERNION_QUAT_HPP
