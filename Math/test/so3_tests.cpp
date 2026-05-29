#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/lie.hpp>
#include <epsilon-math01/matrix.hpp>

namespace epsilon::math {
    namespace {

        TEST_CASE("SO3 aliases and identity construction") {
            CHECK(sizeof(SO3) == sizeof(SO3f));
            CHECK(sizeof(SO3d) == sizeof(f64) * 4);
            CHECK(SO3{} == SO3::identity());
            CHECK(isNearlyEqual(SO3::fromQuat(Quat{2.0F, 0.0F, 0.0F, 0.0F}), SO3::identity()));
        }

        TEST_CASE("SO3 hat and vee convert between vector and skew matrix") {
            Vec3 const   vector{1.0F, 2.0F, 3.0F};
            Mat3x3 const matrix = hat(vector);
            Mat3x3 const expected{
                { 0.0F, -3.0F,  2.0F},
                { 3.0F,  0.0F, -1.0F},
                {-2.0F,  1.0F,  0.0F},
            };

            CHECK(matrix == expected);
            CHECK(vee(matrix) == vector);
            CHECK(isNearlyEqual(matrix * Vec3{4.0F, 5.0F, 6.0F}, cross(vector, Vec3{4.0F, 5.0F, 6.0F})));
        }

        TEST_CASE("SO3 exp and log round trip rotations") {
            CHECK(SO3::exp(Vec3{}) == SO3::identity());
            CHECK(SO3::identity().log() == Vec3{});

            Vec3 const tangent{0.2F, -0.3F, 0.4F};
            SO3 const  rotation = SO3::exp(tangent);

            CHECK(isNearlyEqual(rotation.log(), tangent));
            CHECK(isNearlyEqual(SO3::exp(rotation.log()), rotation));
        }

        TEST_CASE("SO3 rotates with right handed active rotation") {
            SO3 const quarter_turn = SO3::fromAxisAngle(Vec3{0.0F, 0.0F, 1.0F}, kHalfPi);

            CHECK(isNearlyEqual(quarter_turn.rotate(Vec3{1.0F, 0.0F, 0.0F}), Vec3{0.0F, 1.0F, 0.0F}));
            CHECK(isNearlyEqual(quarter_turn.toMat3() * Vec3{1.0F, 0.0F, 0.0F}, Vec3{0.0F, 1.0F, 0.0F}));
        }

        TEST_CASE("SO3 composition inverse and quaternion double cover work") {
            SO3 const  z_turn     = SO3::fromAxisAngle(Vec3{0.0F, 0.0F, 1.0F}, kHalfPi);
            SO3 const  x_turn     = SO3::fromAxisAngle(Vec3{1.0F, 0.0F, 0.0F}, kHalfPi);
            SO3 const  composed   = z_turn * x_turn;
            Vec3 const test_value = Vec3{0.0F, 1.0F, 0.0F};

            CHECK(isNearlyEqual(composed.rotate(test_value), z_turn.rotate(x_turn.rotate(test_value))));
            CHECK(isNearlyEqual(z_turn * z_turn.inverse(), SO3::identity()));

            Quat const quat = z_turn.quat();
            CHECK(isNearlyEqual(SO3::fromQuat(quat), SO3::fromQuat(-quat)));
        }

    } // namespace
} // namespace epsilon::math
