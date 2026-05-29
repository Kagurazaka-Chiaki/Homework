#ifndef EPSILON_MATH_VECTOR_HPP
#define EPSILON_MATH_VECTOR_HPP

#include "epsilon-math01/vector/vec.hpp" // IWYU pragma: export
#include "epsilon-math01/vector/vec2.hpp" // IWYU pragma: export
#include "epsilon-math01/vector/vec3.hpp" // IWYU pragma: export
#include "epsilon-math01/vector/vec4.hpp" // IWYU pragma: export

namespace epsilon::math {

    using Vec2 = Vec<Scalar, 2>;
    using Vec3 = Vec<Scalar, 3>;
    using Vec4 = Vec<Scalar, 4>;

    using Vec2f = Vec<f32, 2>;
    using Vec3f = Vec<f32, 3>;
    using Vec4f = Vec<f32, 4>;

    using Vec2d = Vec<f64, 2>;
    using Vec3d = Vec<f64, 3>;
    using Vec4d = Vec<f64, 4>;

    using Vec2i = Vec<i32, 2>;
    using Vec3i = Vec<i32, 3>;
    using Vec4i = Vec<i32, 4>;

} // namespace epsilon::math

#include "epsilon-math01/vector/vec_ops.hpp" // IWYU pragma: export

#endif // EPSILON_MATH_VECTOR_HPP
