#ifndef EPSILON_MATH_MATRIX_MAT3X3_HPP
#define EPSILON_MATH_MATRIX_MAT3X3_HPP

#include "epsilon-math01/matrix/mat.hpp"

namespace epsilon::math {

    template<ScalarLike T>
    struct Mat<T, 3, 3> : MatrixBase<Mat<T, 3, 3>, T, 3, 3> {
        using Base = MatrixBase<Mat<T, 3, 3>, T, 3, 3>;

        using Base::Base;

        constexpr Mat() noexcept = default;

        [[nodiscard]] constexpr T &m00() noexcept { return (*this)(0, 0); }

        [[nodiscard]] constexpr T &m01() noexcept { return (*this)(0, 1); }

        [[nodiscard]] constexpr T &m02() noexcept { return (*this)(0, 2); }

        [[nodiscard]] constexpr T &m10() noexcept { return (*this)(1, 0); }

        [[nodiscard]] constexpr T &m11() noexcept { return (*this)(1, 1); }

        [[nodiscard]] constexpr T &m12() noexcept { return (*this)(1, 2); }

        [[nodiscard]] constexpr T &m20() noexcept { return (*this)(2, 0); }

        [[nodiscard]] constexpr T &m21() noexcept { return (*this)(2, 1); }

        [[nodiscard]] constexpr T &m22() noexcept { return (*this)(2, 2); }

        [[nodiscard]] constexpr T const &m00() const noexcept { return (*this)(0, 0); }

        [[nodiscard]] constexpr T const &m01() const noexcept { return (*this)(0, 1); }

        [[nodiscard]] constexpr T const &m02() const noexcept { return (*this)(0, 2); }

        [[nodiscard]] constexpr T const &m10() const noexcept { return (*this)(1, 0); }

        [[nodiscard]] constexpr T const &m11() const noexcept { return (*this)(1, 1); }

        [[nodiscard]] constexpr T const &m12() const noexcept { return (*this)(1, 2); }

        [[nodiscard]] constexpr T const &m20() const noexcept { return (*this)(2, 0); }

        [[nodiscard]] constexpr T const &m21() const noexcept { return (*this)(2, 1); }

        [[nodiscard]] constexpr T const &m22() const noexcept { return (*this)(2, 2); }

        [[nodiscard]] constexpr bool operator==(Mat const &) const noexcept = default;
    };

} // namespace epsilon::math

#endif // EPSILON_MATH_MATRIX_MAT3X3_HPP
