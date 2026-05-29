#ifndef EPSILON_MATH_MATRIX_MAT2X2_HPP
#define EPSILON_MATH_MATRIX_MAT2X2_HPP

#include "epsilon-math01/matrix/mat.hpp"

namespace epsilon::math {

    template<ScalarLike T>
    struct Mat<T, 2, 2> : MatrixBase<Mat<T, 2, 2>, T, 2, 2> {
        using Base = MatrixBase<Mat<T, 2, 2>, T, 2, 2>;

        using Base::Base;

        constexpr Mat() noexcept = default;

        [[nodiscard]] constexpr T &m00() noexcept { return (*this)(0, 0); }

        [[nodiscard]] constexpr T &m01() noexcept { return (*this)(0, 1); }

        [[nodiscard]] constexpr T &m10() noexcept { return (*this)(1, 0); }

        [[nodiscard]] constexpr T &m11() noexcept { return (*this)(1, 1); }

        [[nodiscard]] constexpr T const &m00() const noexcept { return (*this)(0, 0); }

        [[nodiscard]] constexpr T const &m01() const noexcept { return (*this)(0, 1); }

        [[nodiscard]] constexpr T const &m10() const noexcept { return (*this)(1, 0); }

        [[nodiscard]] constexpr T const &m11() const noexcept { return (*this)(1, 1); }

        [[nodiscard]] constexpr T &a() noexcept { return m00(); }

        [[nodiscard]] constexpr T &b() noexcept { return m01(); }

        [[nodiscard]] constexpr T &c() noexcept { return m10(); }

        [[nodiscard]] constexpr T &d() noexcept { return m11(); }

        [[nodiscard]] constexpr T const &a() const noexcept { return m00(); }

        [[nodiscard]] constexpr T const &b() const noexcept { return m01(); }

        [[nodiscard]] constexpr T const &c() const noexcept { return m10(); }

        [[nodiscard]] constexpr T const &d() const noexcept { return m11(); }

        [[nodiscard]] constexpr bool operator==(Mat const &) const noexcept = default;
    };

} // namespace epsilon::math

#endif // EPSILON_MATH_MATRIX_MAT2X2_HPP
