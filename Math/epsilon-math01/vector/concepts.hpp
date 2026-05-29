#ifndef EPSILON_MATH_VECTOR_CONCEPTS_HPP
#define EPSILON_MATH_VECTOR_CONCEPTS_HPP

#include "epsilon-math01/scalar/concepts.hpp"
#include <type_traits>

#include <cstddef>

namespace epsilon::math {

    template<class T, std::size_t N>
    struct Vec;

    template<typename T>
    struct IsVec : std::false_type {};

    template<class T, std::size_t N>
    struct IsVec<Vec<T, N>> : std::true_type {};

    template<typename T>
    concept VectorLike = IsVec<std::remove_cvref_t<T>>::value;

    template<typename T>
    concept ArithmeticVectorLike = VectorLike<T> && ArithmeticScalarLike<typename std::remove_cvref_t<T>::ValueType>;

    template<typename T>
    concept FloatingVectorLike = VectorLike<T> && FloatingScalarLike<typename std::remove_cvref_t<T>::ValueType>;

} // namespace epsilon::math

#endif // EPSILON_MATH_VECTOR_CONCEPTS_HPP
