#ifndef EPSILON_MATH_MATRIX_CONCEPTS_HPP
#define EPSILON_MATH_MATRIX_CONCEPTS_HPP

#include "epsilon-math01/scalar/concepts.hpp"
#include <type_traits>

#include <cstddef>

namespace epsilon::math {

    template<class T, std::size_t Rows, std::size_t Cols>
    struct Mat;

    template<typename T>
    struct IsMatrix : std::false_type {};

    template<class T, std::size_t Rows, std::size_t Cols>
    struct IsMatrix<Mat<T, Rows, Cols>> : std::bool_constant<ScalarLike<T>> {};

    template<typename T>
    concept MatrixLike = IsMatrix<std::remove_cvref_t<T>>::value;

    template<typename T>
    concept SquareMatrixLike = MatrixLike<T> && (std::remove_cvref_t<T>::kRows == std::remove_cvref_t<T>::kCols);

    template<typename T>
    concept FloatingMatrixLike = MatrixLike<T> && FloatingScalarLike<typename std::remove_cvref_t<T>::ValueType>;

} // namespace epsilon::math

#endif // EPSILON_MATH_MATRIX_CONCEPTS_HPP
