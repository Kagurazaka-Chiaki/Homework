#ifndef EPSILON_MATH_VECTOR_VEC4_HPP
#define EPSILON_MATH_VECTOR_VEC4_HPP

#include "epsilon-math01/vector/vec.hpp"

namespace epsilon::math {

    template<class T>
    struct Vec<T, 4> {
        static_assert(ArithmeticScalarLike<T>);

        using ValueType                         = T;
        static constexpr std::size_t kDimension = 4;

        T x = T{0};
        T y = T{0};
        T z = T{0};
        T w = T{0};

        constexpr Vec() noexcept = default;

        constexpr Vec(T x_value, T y_value, T z_value, T w_value) noexcept
            : x(x_value)
            , y(y_value)
            , z(z_value)
            , w(w_value) {
        }

        constexpr Vec(std::initializer_list<T> values) noexcept {
            std::size_t index = 0;
            for (T value: values) {
                if (index >= kDimension) {
                    break;
                }
                (*this)[index] = value;
                ++index;
            }
        }

        [[nodiscard]] constexpr T &operator()(std::size_t index) noexcept {
            assert(index < 4);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
                case 3:
                    return w;
                default:
                    std::unreachable();
            }
        }

        [[nodiscard]] constexpr T const &operator()(std::size_t index) const noexcept {
            assert(index < 4);
            switch (index) {
                case 0:
                    return x;
                case 1:
                    return y;
                case 2:
                    return z;
                case 3:
                    return w;
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

        [[nodiscard]] constexpr bool operator==(Vec const &) const noexcept = default;
    };

} // namespace epsilon::math

#endif // EPSILON_MATH_VECTOR_VEC4_HPP
