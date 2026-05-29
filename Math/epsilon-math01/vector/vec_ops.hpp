#ifndef EPSILON_MATH_VECTOR_VEC_OPS_HPP
#define EPSILON_MATH_VECTOR_VEC_OPS_HPP

#include "epsilon-math01/scalar/scalar.hpp"
#include "epsilon-math01/vector/concepts.hpp"

#include <cmath>
#include <cstddef>

namespace epsilon::math {

    template<ArithmeticVectorLike VectorT>
    [[nodiscard]] constexpr VectorT operator+(VectorT lhs, VectorT rhs) noexcept {
        VectorT result{};
        for (std::size_t index = 0; index < VectorT::kDimension; ++index) {
            result[index] = lhs[index] + rhs[index];
        }
        return result;
    }

    template<ArithmeticVectorLike VectorT>
    [[nodiscard]] constexpr VectorT operator-(VectorT lhs, VectorT rhs) noexcept {
        VectorT result{};
        for (std::size_t index = 0; index < VectorT::kDimension; ++index) {
            result[index] = lhs[index] - rhs[index];
        }
        return result;
    }

    template<ArithmeticVectorLike VectorT>
    [[nodiscard]] constexpr VectorT operator-(VectorT value) noexcept {
        VectorT result{};
        for (std::size_t index = 0; index < VectorT::kDimension; ++index) {
            result[index] = -value[index];
        }
        return result;
    }

    template<ArithmeticVectorLike VectorT>
    [[nodiscard]] constexpr VectorT operator*(VectorT value, typename VectorT::ValueType scalar) noexcept {
        VectorT result{};
        for (std::size_t index = 0; index < VectorT::kDimension; ++index) {
            result[index] = value[index] * scalar;
        }
        return result;
    }

    template<ArithmeticVectorLike VectorT>
    [[nodiscard]] constexpr VectorT operator*(typename VectorT::ValueType scalar, VectorT value) noexcept {
        return value * scalar;
    }

    template<ArithmeticVectorLike VectorT>
    [[nodiscard]] constexpr VectorT operator/(VectorT value, typename VectorT::ValueType scalar) noexcept {
        VectorT result{};
        for (std::size_t index = 0; index < VectorT::kDimension; ++index) {
            result[index] = value[index] / scalar;
        }
        return result;
    }

    template<ArithmeticVectorLike VectorT>
    constexpr VectorT &operator+=(VectorT &lhs, VectorT rhs) noexcept {
        lhs = lhs + rhs;
        return lhs;
    }

    template<ArithmeticVectorLike VectorT>
    constexpr VectorT &operator-=(VectorT &lhs, VectorT rhs) noexcept {
        lhs = lhs - rhs;
        return lhs;
    }

    template<ArithmeticVectorLike VectorT>
    constexpr VectorT &operator*=(VectorT &value, typename VectorT::ValueType scalar) noexcept {
        value = value * scalar;
        return value;
    }

    template<ArithmeticVectorLike VectorT>
    constexpr VectorT &operator/=(VectorT &value, typename VectorT::ValueType scalar) noexcept {
        value = value / scalar;
        return value;
    }

    template<ArithmeticVectorLike VectorT>
    [[nodiscard]] constexpr typename VectorT::ValueType dot(VectorT lhs, VectorT rhs) noexcept {
        typename VectorT::ValueType result{};
        for (std::size_t index = 0; index < VectorT::kDimension; ++index) {
            result += lhs[index] * rhs[index];
        }
        return result;
    }

    template<ArithmeticVectorLike VectorT>
    [[nodiscard]] constexpr typename VectorT::ValueType normSquared(VectorT value) noexcept {
        return dot(value, value);
    }

    template<FloatingVectorLike VectorT>
    [[nodiscard]] typename VectorT::ValueType length(VectorT value) noexcept {
        return std::sqrt(normSquared(value));
    }

    template<FloatingVectorLike VectorT>
    [[nodiscard]] typename VectorT::ValueType norm(VectorT value, int order = 2) noexcept {
        using T = typename VectorT::ValueType;

        if (order < 0) {
            return T{0};
        }
        if (order == 0) {
            T result = abs(value[0]);
            for (std::size_t index = 1; index < VectorT::kDimension; ++index) {
                result = maximum(result, abs(value[index]));
            }
            return result;
        }
        if (order == 1) {
            T result{};
            for (std::size_t index = 0; index < VectorT::kDimension; ++index) {
                result += abs(value[index]);
            }
            return result;
        }
        if (order == 2) {
            return length(value);
        }

        T result{};
        if (order == 3) {
            for (std::size_t index = 0; index < VectorT::kDimension; ++index) {
                T const component = abs(value[index]);
                result += component * component * component;
            }
            return std::cbrt(result);
        }

        T const exponent = static_cast<T>(order);
        for (std::size_t index = 0; index < VectorT::kDimension; ++index) {
            result += std::pow(abs(value[index]), exponent);
        }
        return std::pow(result, T{1} / exponent);
    }

    template<FloatingVectorLike VectorT>
    [[nodiscard]] VectorT normalized(VectorT value, typename VectorT::ValueType epsilon = kEpsilonV<typename VectorT::ValueType>) noexcept {
        auto const vector_length = length(value);
        return isNearlyZero(vector_length, epsilon) ? VectorT{} : value / vector_length;
    }

    template<FloatingVectorLike VectorT>
    [[nodiscard]] constexpr bool isNearlyEqual(VectorT lhs, VectorT rhs, typename VectorT::ValueType epsilon = kEpsilonV<typename VectorT::ValueType>) noexcept {
        for (std::size_t index = 0; index < VectorT::kDimension; ++index) {
            if (!isNearlyEqual(lhs[index], rhs[index], epsilon)) {
                return false;
            }
        }
        return true;
    }

} // namespace epsilon::math

#include "epsilon-math01/vector/vec3_ops.hpp" // IWYU pragma: export

#endif // EPSILON_MATH_VECTOR_VEC_OPS_HPP
