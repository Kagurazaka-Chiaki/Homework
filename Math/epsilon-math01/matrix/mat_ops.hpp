#ifndef EPSILON_MATH_MATRIX_MAT_OPS_HPP
#define EPSILON_MATH_MATRIX_MAT_OPS_HPP

#include "epsilon-math01/matrix/mat.hpp"
#include "epsilon-math01/vector.hpp"

#include <cstddef>

namespace epsilon::math {

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    [[nodiscard]] constexpr Mat<T, Cols, Rows> transpose(Mat<T, Rows, Cols> value) noexcept {
        Mat<T, Cols, Rows> result{};
        for (std::size_t row = 0; row < Rows; ++row) {
            for (std::size_t col = 0; col < Cols; ++col) {
                result(col, row) = value(row, col);
            }
        }
        return result;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    [[nodiscard]] constexpr Mat<T, Rows, Cols> operator+(Mat<T, Rows, Cols> lhs, Mat<T, Rows, Cols> rhs) noexcept {
        Mat<T, Rows, Cols> result{};
        for (std::size_t row = 0; row < Rows; ++row) {
            for (std::size_t col = 0; col < Cols; ++col) {
                result(row, col) = lhs(row, col) + rhs(row, col);
            }
        }
        return result;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    [[nodiscard]] constexpr Mat<T, Rows, Cols> operator-(Mat<T, Rows, Cols> lhs, Mat<T, Rows, Cols> rhs) noexcept {
        Mat<T, Rows, Cols> result{};
        for (std::size_t row = 0; row < Rows; ++row) {
            for (std::size_t col = 0; col < Cols; ++col) {
                result(row, col) = lhs(row, col) - rhs(row, col);
            }
        }
        return result;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    [[nodiscard]] constexpr Mat<T, Rows, Cols> operator-(Mat<T, Rows, Cols> value) noexcept {
        Mat<T, Rows, Cols> result{};
        for (std::size_t row = 0; row < Rows; ++row) {
            for (std::size_t col = 0; col < Cols; ++col) {
                result(row, col) = -value(row, col);
            }
        }
        return result;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    [[nodiscard]] constexpr Mat<T, Rows, Cols> operator*(Mat<T, Rows, Cols> value, T scalar) noexcept {
        Mat<T, Rows, Cols> result{};
        for (std::size_t row = 0; row < Rows; ++row) {
            for (std::size_t col = 0; col < Cols; ++col) {
                result(row, col) = value(row, col) * scalar;
            }
        }
        return result;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    [[nodiscard]] constexpr Mat<T, Rows, Cols> operator*(T scalar, Mat<T, Rows, Cols> value) noexcept {
        return value * scalar;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    [[nodiscard]] constexpr Mat<T, Rows, Cols> operator/(Mat<T, Rows, Cols> value, T scalar) noexcept {
        Mat<T, Rows, Cols> result{};
        for (std::size_t row = 0; row < Rows; ++row) {
            for (std::size_t col = 0; col < Cols; ++col) {
                result(row, col) = value(row, col) / scalar;
            }
        }
        return result;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    constexpr Mat<T, Rows, Cols> &operator+=(Mat<T, Rows, Cols> &lhs, Mat<T, Rows, Cols> rhs) noexcept {
        lhs = lhs + rhs;
        return lhs;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    constexpr Mat<T, Rows, Cols> &operator-=(Mat<T, Rows, Cols> &lhs, Mat<T, Rows, Cols> rhs) noexcept {
        lhs = lhs - rhs;
        return lhs;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    constexpr Mat<T, Rows, Cols> &operator*=(Mat<T, Rows, Cols> &value, T scalar) noexcept {
        value = value * scalar;
        return value;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    constexpr Mat<T, Rows, Cols> &operator/=(Mat<T, Rows, Cols> &value, T scalar) noexcept {
        value = value / scalar;
        return value;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Inner, std::size_t Cols>
    [[nodiscard]] constexpr Mat<T, Rows, Cols> operator*(Mat<T, Rows, Inner> lhs, Mat<T, Inner, Cols> rhs) noexcept {
        Mat<T, Rows, Cols> result{};
        for (std::size_t row = 0; row < Rows; ++row) {
            for (std::size_t col = 0; col < Cols; ++col) {
                for (std::size_t inner = 0; inner < Inner; ++inner) {
                    result(row, col) += lhs(row, inner) * rhs(inner, col);
                }
            }
        }
        return result;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    [[nodiscard]] constexpr Vec<T, Rows> operator*(Mat<T, Rows, Cols> matrix, Vec<T, Cols> vector) noexcept {
        Vec<T, Rows> result{};
        for (std::size_t row = 0; row < Rows; ++row) {
            for (std::size_t col = 0; col < Cols; ++col) {
                result[row] += matrix(row, col) * vector[col];
            }
        }
        return result;
    }

    template<ScalarLike T, std::size_t Rows, std::size_t Cols>
    [[nodiscard]] constexpr bool isNearlyEqual(Mat<T, Rows, Cols> lhs, Mat<T, Rows, Cols> rhs, T epsilon = kEpsilonV<T>) noexcept {
        for (std::size_t row = 0; row < Rows; ++row) {
            for (std::size_t col = 0; col < Cols; ++col) {
                if (!isNearlyEqual(lhs(row, col), rhs(row, col), epsilon)) {
                    return false;
                }
            }
        }
        return true;
    }

} // namespace epsilon::math

#endif // EPSILON_MATH_MATRIX_MAT_OPS_HPP
