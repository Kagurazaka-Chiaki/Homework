#ifndef EPSILON_MATH_LIE_SE3_HPP
#define EPSILON_MATH_LIE_SE3_HPP

#include "epsilon-math01/lie/so3.hpp"
#include "epsilon-math01/matrix/mat4x4.hpp"
#include "epsilon-math01/matrix/mat_ops.hpp"
#include "epsilon-math01/scalar.hpp"
#include "epsilon-math01/vector.hpp"

#include <cmath>
#include <cstddef>

namespace epsilon::math {

    namespace detail {

        /**
         * 计算 SO(3) 左雅可比矩阵 J(w)。
         *
         * 设 W = hat(w), theta = ||w||：
         * \f[
         * J(w) = I + \frac{1-\cos\theta}{\theta^2} W
         *          + \frac{\theta-\sin\theta}{\theta^3} W^2
         * \f]
         *
         * 在 SE(3) 指数映射中，平移部分满足：
         * \f[
         * t = J(w)v
         * \f]
         *
         * 当 theta 接近 0 时使用泰勒展开，避免除以很小的角度。
         */
        template<ScalarLike T>
        [[nodiscard]] Mat<T, 3, 3> so3LeftJacobian(Vec<T, 3> omega) noexcept {
            T const            theta_squared = normSquared(omega);
            Mat<T, 3, 3> const omega_hat     = hat(omega);
            Mat<T, 3, 3> const omega_hat2    = omega_hat * omega_hat;

            T a{};
            T b{};
            if (theta_squared <= kEpsilonV<T>) {
                a = T{0.5} - theta_squared / T{24} + theta_squared * theta_squared / T{720};
                b = T{1} / T{6} - theta_squared / T{120} + theta_squared * theta_squared / T{5040};
            } else {
                T const theta = std::sqrt(theta_squared);
                a             = (T{1} - std::cos(theta)) / theta_squared;
                b             = (theta - std::sin(theta)) / (theta_squared * theta);
            }

            return Mat<T, 3, 3>::identity() + omega_hat * a + omega_hat2 * b;
        }

        /**
         * 计算 SO(3) 左雅可比逆矩阵 J(w)^{-1}。
         *
         * 设 W = hat(w), theta = ||w||：
         * \f[
         * J(w)^{-1} = I - \frac{1}{2}W
         *              + \left(
         *                  \frac{1}{\theta^2}
         *                  - \frac{1+\cos\theta}{2\theta\sin\theta}
         *                \right) W^2
         * \f]
         *
         * 在 SE(3) 对数映射中，速度部分满足：
         * \f[
         * v = J(w)^{-1}t
         * \f]
         *
         * 当 theta 接近 0 时使用泰勒展开，避免除以很小的角度。
         */
        template<ScalarLike T>
        [[nodiscard]] Mat<T, 3, 3> so3LeftJacobianInverse(Vec<T, 3> omega) noexcept {
            T const            theta_squared = normSquared(omega);
            Mat<T, 3, 3> const omega_hat     = hat(omega);
            Mat<T, 3, 3> const omega_hat2    = omega_hat * omega_hat;

            T c{};
            if (theta_squared <= kEpsilonV<T>) {
                c = T{1} / T{12} + theta_squared / T{720} + theta_squared * theta_squared / T{30240};
            } else {
                T const theta = std::sqrt(theta_squared);
                c             = T{1} / theta_squared - (T{1} + std::cos(theta)) / (T{2} * theta * std::sin(theta));
            }

            return Mat<T, 3, 3>::identity() - omega_hat * T{0.5} + omega_hat2 * c;
        }

    } // namespace detail

    template<ScalarLike T>
    class SE3T {
      public:
        using ValueType   = T;
        using TangentType = Vec<T, 6>;

        constexpr SE3T() noexcept = default;

        [[nodiscard]] static constexpr SE3T identity() noexcept {
            return {};
        }

        [[nodiscard]] static constexpr SE3T fromRotationTranslation(SO3T<T> rotation, Vec<T, 3> translation) noexcept {
            return SE3T{rotation, translation};
        }

        [[nodiscard]] static SE3T exp(TangentType tangent) noexcept {
            Vec<T, 3> const omega{tangent[0], tangent[1], tangent[2]};
            Vec<T, 3> const velocity{tangent[3], tangent[4], tangent[5]};
            SO3T<T> const   rotation    = SO3T<T>::exp(omega);
            Vec<T, 3> const translation = detail::so3LeftJacobian(omega) * velocity;
            return fromRotationTranslation(rotation, translation);
        }

        [[nodiscard]] TangentType log() const noexcept {
            Vec<T, 3> const omega    = rotation_.log();
            Vec<T, 3> const velocity = detail::so3LeftJacobianInverse(omega) * translation_;
            return {omega.x, omega.y, omega.z, velocity.x, velocity.y, velocity.z};
        }

        [[nodiscard]] SE3T inverse() const noexcept {
            SO3T<T> const   rotation_inverse    = rotation_.inverse();
            Vec<T, 3> const translation_inverse = rotation_inverse.rotate(-translation_);
            return fromRotationTranslation(rotation_inverse, translation_inverse);
        }

        [[nodiscard]] constexpr SO3T<T> rotation() const noexcept {
            return rotation_;
        }

        [[nodiscard]] constexpr Vec<T, 3> translation() const noexcept {
            return translation_;
        }

        [[nodiscard]] Mat<T, 4, 4> toMat4() const noexcept {
            Mat<T, 4, 4> result   = Mat<T, 4, 4>::identity();
            Mat<T, 3, 3> rotation = rotation_.toMat3();

            for (std::size_t row = 0; row < 3; ++row) {
                for (std::size_t col = 0; col < 3; ++col) {
                    result(row, col) = rotation(row, col);
                }
            }

            result(0, 3) = translation_.x;
            result(1, 3) = translation_.y;
            result(2, 3) = translation_.z;
            return result;
        }

        [[nodiscard]] Vec<T, 3> transformPoint(Vec<T, 3> point) const noexcept {
            return rotation_.rotate(point) + translation_;
        }

        [[nodiscard]] Vec<T, 3> transformVector(Vec<T, 3> vector) const noexcept {
            return rotation_.rotate(vector);
        }

        [[nodiscard]] constexpr bool operator==(SE3T const &) const noexcept = default;

      private:
        constexpr SE3T(SO3T<T> rotation, Vec<T, 3> translation) noexcept
            : rotation_(rotation)
            , translation_(translation) {
        }

        SO3T<T>   rotation_{};
        Vec<T, 3> translation_{};
    };

    using SE3  = SE3T<Scalar>;
    using SE3f = SE3T<f32>;
    using SE3d = SE3T<f64>;

    template<ScalarLike T>
    [[nodiscard]] SE3T<T> operator*(SE3T<T> lhs, SE3T<T> rhs) noexcept {
        return SE3T<T>::fromRotationTranslation(lhs.rotation() * rhs.rotation(), lhs.rotation().rotate(rhs.translation()) + lhs.translation());
    }

    template<ScalarLike T>
    [[nodiscard]] bool isNearlyEqual(SE3T<T> lhs, SE3T<T> rhs, T epsilon = kEpsilonV<T>) noexcept {
        return isNearlyEqual(lhs.rotation(), rhs.rotation(), epsilon) && isNearlyEqual(lhs.translation(), rhs.translation(), epsilon);
    }

} // namespace epsilon::math

#endif // EPSILON_MATH_LIE_SE3_HPP
