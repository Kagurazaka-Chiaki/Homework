#ifndef EPSILON_MATH_MATRIX_MAT_HPP
#define EPSILON_MATH_MATRIX_MAT_HPP

#include "epsilon-math01/scalar/scalar.hpp"
#include <initializer_list>

#include <array>
#include <cassert>
#include <cstddef>

namespace epsilon::math {

    template<class T, std::size_t Rows, std::size_t Cols = Rows>
    struct Mat;

    // 预留给未来的大型稀疏矩阵；小型固定尺寸 Mat<T, Rows, Cols> 保持稠密存储。
    template<class T>
    struct SparseMatCsr;

    template<std::size_t Rows, std::size_t Cols>
    struct MatrixDimensionCompat {
        [[nodiscard]] constexpr bool operator==(MatrixDimensionCompat const &) const noexcept = default;
    };

    template<std::size_t Dimension>
    struct MatrixDimensionCompat<Dimension, Dimension> {
        static constexpr std::size_t kDimension = Dimension;

        [[nodiscard]] constexpr bool operator==(MatrixDimensionCompat const &) const noexcept = default;
    };

    template<class DerivedT, ScalarLike T, std::size_t Rows, std::size_t Cols>
    struct MatrixBase : MatrixDimensionCompat<Rows, Cols> {
        static_assert(Rows > 0);
        static_assert(Cols > 0);

        using ValueType                            = T;
        static constexpr std::size_t kRows         = Rows;
        static constexpr std::size_t kCols         = Cols;
        static constexpr std::size_t kElementCount = Rows * Cols;

        // Row-major contiguous storage: data[row * Cols + col].
        std::array<T, kElementCount> data{};

        constexpr MatrixBase() noexcept = default;

        constexpr MatrixBase(std::initializer_list<T> values) noexcept {
            std::size_t index = 0;
            for (T value: values) {
                if (index >= kElementCount) {
                    break;
                }
                data[index] = value;
                ++index;
            }
        }

        constexpr MatrixBase(std::initializer_list<std::initializer_list<T>> rows) noexcept {
            std::size_t row = 0;
            for (std::initializer_list<T> values: rows) {
                if (row >= kRows) {
                    break;
                }

                std::size_t col = 0;
                for (T value: values) {
                    if (col >= kCols) {
                        break;
                    }
                    (*this)(row, col) = value;
                    ++col;
                }
                ++row;
            }
        }

        [[nodiscard]] constexpr T &operator()(std::size_t row, std::size_t col) noexcept {
            assert(row < Rows && col < Cols);
            return data[row * Cols + col];
        }

        [[nodiscard]] constexpr T const &operator()(std::size_t row, std::size_t col) const noexcept {
            assert(row < Rows && col < Cols);
            return data[row * Cols + col];
        }

        [[nodiscard]] constexpr T *raw() noexcept {
            return data.data();
        }

        [[nodiscard]] constexpr T const *raw() const noexcept {
            return data.data();
        }

        [[nodiscard]] constexpr T *operator[](std::size_t row) noexcept {
            assert(row < Rows);
            return raw() + row * Cols;
        }

        [[nodiscard]] constexpr T const *operator[](std::size_t row) const noexcept {
            assert(row < Rows);
            return raw() + row * Cols;
        }

        [[nodiscard]] static constexpr DerivedT zero() noexcept {
            return {};
        }

        [[nodiscard]] static constexpr DerivedT identity() noexcept
            requires(Rows == Cols)
        {
            DerivedT result{};
            for (std::size_t index = 0; index < Rows; ++index) {
                result(index, index) = T{1};
            }
            return result;
        }

        [[nodiscard]] constexpr bool operator==(MatrixBase const &) const noexcept = default;
    };

    template<class T, std::size_t Rows, std::size_t Cols>
    struct Mat : MatrixBase<Mat<T, Rows, Cols>, T, Rows, Cols> {
        static_assert(ScalarLike<T>);

        using Base = MatrixBase<Mat<T, Rows, Cols>, T, Rows, Cols>;

        using Base::Base;

        constexpr Mat() noexcept = default;

        [[nodiscard]] constexpr bool operator==(Mat const &) const noexcept = default;
    };

} // namespace epsilon::math

#endif // EPSILON_MATH_MATRIX_MAT_HPP
