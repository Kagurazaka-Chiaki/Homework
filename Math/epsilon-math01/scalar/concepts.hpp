#ifndef EPSILON_MATH_SCALAR_CONCEPTS_HPP
#define EPSILON_MATH_SCALAR_CONCEPTS_HPP

#include <type_traits>

#include <concepts>

namespace epsilon::math {

    template<typename T>
    concept ArithmeticScalarLike = std::is_arithmetic_v<std::remove_cvref_t<T>>;

    template<typename T>
    concept FloatingScalarLike = std::floating_point<std::remove_cvref_t<T>>;

    template<typename T>
    concept ScalarLike = FloatingScalarLike<T>;

} // namespace epsilon::math

#endif // EPSILON_MATH_SCALAR_CONCEPTS_HPP
