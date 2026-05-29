#ifndef EPSILON_MATH_MATRIX_HPP
#define EPSILON_MATH_MATRIX_HPP

#include "epsilon-math01/matrix/mat.hpp" // IWYU pragma: export
#include "epsilon-math01/matrix/mat2x2.hpp" // IWYU pragma: export
#include "epsilon-math01/matrix/mat2x3.hpp" // IWYU pragma: export
#include "epsilon-math01/matrix/mat2x4.hpp" // IWYU pragma: export
#include "epsilon-math01/matrix/mat3x2.hpp" // IWYU pragma: export
#include "epsilon-math01/matrix/mat3x3.hpp" // IWYU pragma: export
#include "epsilon-math01/matrix/mat3x4.hpp" // IWYU pragma: export
#include "epsilon-math01/matrix/mat4x2.hpp" // IWYU pragma: export
#include "epsilon-math01/matrix/mat4x3.hpp" // IWYU pragma: export
#include "epsilon-math01/matrix/mat4x4.hpp" // IWYU pragma: export
#include "epsilon-math01/vector.hpp" // IWYU pragma: export

namespace epsilon::math {

    using Mat2x2 = Mat<Scalar, 2, 2>;
    using Mat2x3 = Mat<Scalar, 2, 3>;
    using Mat2x4 = Mat<Scalar, 2, 4>;
    using Mat3x2 = Mat<Scalar, 3, 2>;
    using Mat3x3 = Mat<Scalar, 3, 3>;
    using Mat3x4 = Mat<Scalar, 3, 4>;
    using Mat4x2 = Mat<Scalar, 4, 2>;
    using Mat4x3 = Mat<Scalar, 4, 3>;
    using Mat4x4 = Mat<Scalar, 4, 4>;

    using Mat2x2f = Mat<f32, 2, 2>;
    using Mat2x3f = Mat<f32, 2, 3>;
    using Mat2x4f = Mat<f32, 2, 4>;
    using Mat3x2f = Mat<f32, 3, 2>;
    using Mat3x3f = Mat<f32, 3, 3>;
    using Mat3x4f = Mat<f32, 3, 4>;
    using Mat4x2f = Mat<f32, 4, 2>;
    using Mat4x3f = Mat<f32, 4, 3>;
    using Mat4x4f = Mat<f32, 4, 4>;

    using Mat2x2d = Mat<f64, 2, 2>;
    using Mat2x3d = Mat<f64, 2, 3>;
    using Mat2x4d = Mat<f64, 2, 4>;
    using Mat3x2d = Mat<f64, 3, 2>;
    using Mat3x3d = Mat<f64, 3, 3>;
    using Mat3x4d = Mat<f64, 3, 4>;
    using Mat4x2d = Mat<f64, 4, 2>;
    using Mat4x3d = Mat<f64, 4, 3>;
    using Mat4x4d = Mat<f64, 4, 4>;

} // namespace epsilon::math

#include "epsilon-math01/matrix/mat_ops.hpp" // IWYU pragma: export

#endif // EPSILON_MATH_MATRIX_HPP
