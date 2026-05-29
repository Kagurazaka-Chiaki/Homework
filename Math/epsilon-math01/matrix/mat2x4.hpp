#ifndef EPSILON_MATH_MATRIX_MAT2X4_HPP
#define EPSILON_MATH_MATRIX_MAT2X4_HPP

#include "epsilon-math01/matrix/mat.hpp"

namespace epsilon::math {

    template<ScalarLike T>
    struct Mat<T, 2, 4> : MatrixBase<Mat<T, 2, 4>, T, 2, 4> {
        using Base = MatrixBase<Mat<T, 2, 4>, T, 2, 4>;

        using Base::Base;

        constexpr Mat() noexcept = default;

        [[nodiscard]] constexpr T &m00() noexcept { return (*this)(0, 0); }

        [[nodiscard]] constexpr T &m01() noexcept { return (*this)(0, 1); }

        [[nodiscard]] constexpr T &m02() noexcept { return (*this)(0, 2); }

        [[nodiscard]] constexpr T &m03() noexcept { return (*this)(0, 3); }

        [[nodiscard]] constexpr T &m10() noexcept { return (*this)(1, 0); }

        [[nodiscard]] constexpr T &m11() noexcept { return (*this)(1, 1); }

        [[nodiscard]] constexpr T &m12() noexcept { return (*this)(1, 2); }

        [[nodiscard]] constexpr T &m13() noexcept { return (*this)(1, 3); }

        [[nodiscard]] constexpr T const &m00() const noexcept { return (*this)(0, 0); }

        [[nodiscard]] constexpr T const &m01() const noexcept { return (*this)(0, 1); }

        [[nodiscard]] constexpr T const &m02() const noexcept { return (*this)(0, 2); }

        [[nodiscard]] constexpr T const &m03() const noexcept { return (*this)(0, 3); }

        [[nodiscard]] constexpr T const &m10() const noexcept { return (*this)(1, 0); }

        [[nodiscard]] constexpr T const &m11() const noexcept { return (*this)(1, 1); }

        [[nodiscard]] constexpr T const &m12() const noexcept { return (*this)(1, 2); }

        [[nodiscard]] constexpr T const &m13() const noexcept { return (*this)(1, 3); }

        [[nodiscard]] constexpr bool operator==(Mat const &) const noexcept = default;
    };

} // namespace epsilon::math

#endif // EPSILON_MATH_MATRIX_MAT2X4_HPP
