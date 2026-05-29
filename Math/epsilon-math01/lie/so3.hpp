#ifndef EPSILON_MATH_LIE_SO3_HPP
#define EPSILON_MATH_LIE_SO3_HPP

#include "epsilon-math01/matrix/mat3x3.hpp"
#include "epsilon-math01/matrix/mat_ops.hpp"
#include "epsilon-math01/quaternion.hpp"
#include "epsilon-math01/scalar.hpp"
#include "epsilon-math01/vector.hpp"

#include <cmath>

namespace epsilon::math {

    /**
     * 将 so(3) 旋转向量转换为反对称矩阵。
     *
     * 返回矩阵满足 hat(w) * v == cross(w, v)，常用于 Rodrigues 公式和 SE(3)
     * 左雅可比计算。
     */
    template<ScalarLike T>
    [[nodiscard]] constexpr Mat<T, 3, 3> hat(Vec<T, 3> vector) noexcept {
        return {
            {     T{0}, -vector.z,  vector.y},
            { vector.z,      T{0}, -vector.x},
            {-vector.y,  vector.x,      T{0}},
        };
    }

    /**
     * 将 so(3) 反对称矩阵转换回旋转向量。
     *
     * 对标准 hat(w) 矩阵，vee(hat(w)) == w。这里对上下三角的差取平均，
     * 能容忍输入矩阵存在轻微的数值非反对称误差。
     */
    template<ScalarLike T>
    [[nodiscard]] constexpr Vec<T, 3> vee(Mat<T, 3, 3> matrix) noexcept {
        return {
            (matrix(2, 1) - matrix(1, 2)) / T{2},
            (matrix(0, 2) - matrix(2, 0)) / T{2},
            (matrix(1, 0) - matrix(0, 1)) / T{2},
        };
    }

    template<ScalarLike T>
    class SO3T {
      public:
        using ValueType   = T;
        using TangentType = Vec<T, 3>;

        constexpr SO3T() noexcept = default;

        [[nodiscard]] static constexpr SO3T identity() noexcept {
            return {};
        }

        [[nodiscard]] static SO3T fromQuat(QuatT<T> quat) noexcept {
            return SO3T{normalized(quat)};
        }

        [[nodiscard]] static SO3T fromAxisAngle(Vec<T, 3> axis, T radians) noexcept {
            return fromQuat(epsilon::math::fromAxisAngle(axis, radians));
        }

        [[nodiscard]] static SO3T exp(TangentType tangent) noexcept {
            T const theta_squared = normSquared(tangent);
            T const theta         = std::sqrt(theta_squared);
            T const half_theta    = theta * T{0.5};

            T real{};
            T scale{};
            if (theta_squared <= kEpsilonV<T>) {
                real  = T{1} - theta_squared / T{8} + theta_squared * theta_squared / T{384};
                scale = T{0.5} - theta_squared / T{48} + theta_squared * theta_squared / T{3840};
            } else {
                real  = std::cos(half_theta);
                scale = std::sin(half_theta) / theta;
            }

            return fromQuat({real, tangent.x * scale, tangent.y * scale, tangent.z * scale});
        }

        /**
         * 将 SO(3) 旋转映射回 so(3) 旋转向量。
         *
         * 返回向量的方向是旋转轴，长度是旋转角度（弧度）。四元数 q 和 -q 表示同一个旋转；
         * 这里选取 w >= 0 的主分支，使结果角度落在较短旋转路径上。
         */
        [[nodiscard]] TangentType log() const noexcept {
            QuatT<T> unit = normalized(quat_);
            if (unit.w < T{0}) {
                unit = -unit;
            }

            T const vector_norm = std::sqrt(unit.x * unit.x + unit.y * unit.y + unit.z * unit.z);
            if (isNearlyZero(vector_norm)) {
                return {T{2} * unit.x, T{2} * unit.y, T{2} * unit.z};
            }

            T const angle = T{2} * std::atan2(vector_norm, unit.w);
            T const scale = angle / vector_norm;
            return {unit.x * scale, unit.y * scale, unit.z * scale};
        }

        [[nodiscard]] SO3T inverse() const noexcept {
            return fromQuat(conjugate(quat_));
        }

        [[nodiscard]] constexpr QuatT<T> quat() const noexcept {
            return quat_;
        }

        [[nodiscard]] Mat<T, 3, 3> toMat3() const noexcept {
            return epsilon::math::toMat3(quat_);
        }

        [[nodiscard]] Vec<T, 3> rotate(Vec<T, 3> vector) const noexcept {
            return epsilon::math::rotate(quat_, vector);
        }

        [[nodiscard]] constexpr bool operator==(SO3T const &) const noexcept = default;

      private:
        explicit constexpr SO3T(QuatT<T> quat) noexcept
            : quat_(quat) {
        }

        QuatT<T> quat_{};
    };

    using SO3  = SO3T<Scalar>;
    using SO3f = SO3T<f32>;
    using SO3d = SO3T<f64>;

    template<ScalarLike T>
    [[nodiscard]] SO3T<T> operator*(SO3T<T> lhs, SO3T<T> rhs) noexcept {
        return SO3T<T>::fromQuat(lhs.quat() * rhs.quat());
    }

    template<ScalarLike T>
    [[nodiscard]] bool isNearlyEqual(SO3T<T> lhs, SO3T<T> rhs, T epsilon = kEpsilonV<T>) noexcept {
        QuatT<T> const lhs_quat = lhs.quat();
        QuatT<T> const rhs_quat = rhs.quat();
        return isNearlyEqual(lhs_quat, rhs_quat, epsilon) || isNearlyEqual(lhs_quat, -rhs_quat, epsilon);
    }

} // namespace epsilon::math

#endif // EPSILON_MATH_LIE_SO3_HPP
