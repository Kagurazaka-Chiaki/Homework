#ifndef EPSILON_MATH_VECTOR_VEC3_OPS_HPP
#define EPSILON_MATH_VECTOR_VEC3_OPS_HPP

#include "epsilon-math01/vector/concepts.hpp"
#include "epsilon-math01/vector/vec3.hpp"

namespace epsilon::math {

    template<ArithmeticScalarLike T>
    [[nodiscard]] constexpr Vec<T, 3> cross(Vec<T, 3> lhs, Vec<T, 3> rhs) noexcept {
        return {
            lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z,
            lhs.x * rhs.y - lhs.y * rhs.x,
        };
    }

} // namespace epsilon::math

#endif // EPSILON_MATH_VECTOR_VEC3_OPS_HPP
