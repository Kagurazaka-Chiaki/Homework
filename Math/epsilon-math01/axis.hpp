#ifndef EPSILON_MATH_AXIS_HPP
#define EPSILON_MATH_AXIS_HPP

namespace epsilon::math {

    enum class Axis2 {
        X,
        Y,
    };

    enum class Axis3 {
        X,
        Y,
        Z,
    };

    enum class Sign {
        Positive,
        Negative,
    };

    struct AxisDirection2 {
        Axis2 axis = Axis2::X;
        Sign  sign = Sign::Positive;

        [[nodiscard]] constexpr bool operator==(AxisDirection2 const &) const noexcept = default;
    };

    struct AxisDirection3 {
        Axis3 axis = Axis3::X;
        Sign  sign = Sign::Positive;

        [[nodiscard]] constexpr bool operator==(AxisDirection3 const &) const noexcept = default;
    };

} // namespace epsilon::math

#endif // EPSILON_MATH_AXIS_HPP
