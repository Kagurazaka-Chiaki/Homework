#ifndef EPSILON_MATH_VECTOR_VEC_HPP
#define EPSILON_MATH_VECTOR_VEC_HPP

#include "epsilon-math01/scalar/scalar.hpp"
#include "epsilon-math01/vector/concepts.hpp"
#include <initializer_list>

#include <array>
#include <cassert>
#include <cstddef>
#include <utility>

namespace epsilon::math {

    template<class T, std::size_t N>
    struct Vec {
        static_assert(N > 0);
        static_assert(ArithmeticScalarLike<T>);

        using ValueType                         = T;
        static constexpr std::size_t kDimension = N;

        std::array<T, N> data{};

        constexpr Vec() noexcept = default;

        constexpr Vec(std::initializer_list<T> values) noexcept {
            std::size_t index = 0;
            for (T value: values) {
                if (index >= data.size()) {
                    break;
                }
                data[index] = value;
                ++index;
            }
        }

        [[nodiscard]] constexpr T &operator()(std::size_t index) noexcept {
            assert(index < N);
            return data[index];
        }

        [[nodiscard]] constexpr T const &operator()(std::size_t index) const noexcept {
            assert(index < N);
            return data[index];
        }

        [[nodiscard]] constexpr T &operator[](std::size_t index) noexcept {
            return (*this)(index);
        }

        [[nodiscard]] constexpr T const &operator[](std::size_t index) const noexcept {
            return (*this)(index);
        }

        [[nodiscard]] constexpr bool operator==(Vec const &) const noexcept = default;
    };

} // namespace epsilon::math

#endif // EPSILON_MATH_VECTOR_VEC_HPP
