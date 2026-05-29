#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/lie.hpp>
#include <epsilon-math01/matrix.hpp>

namespace epsilon::math {
    namespace {

        TEST_CASE("SE3 aliases and identity transform construction") {
            CHECK(sizeof(SE3) == sizeof(SE3f));
            CHECK(sizeof(SE3d) == sizeof(f64) * 7);

            SE3 const identity = SE3::identity();
            CHECK(identity == SE3{});
            CHECK(identity.transformPoint(Vec3{1.0F, 2.0F, 3.0F}) == Vec3{1.0F, 2.0F, 3.0F});
            CHECK(identity.transformVector(Vec3{1.0F, 2.0F, 3.0F}) == Vec3{1.0F, 2.0F, 3.0F});
        }

        TEST_CASE("SE3 exp and log handle pure translation") {
            Vec<Scalar, 6> const tangent{0.0F, 0.0F, 0.0F, 1.0F, 2.0F, 3.0F};
            SE3 const            transform = SE3::exp(tangent);

            CHECK(transform.rotation() == SO3::identity());
            CHECK(transform.translation() == Vec3{1.0F, 2.0F, 3.0F});
            CHECK(transform.log() == tangent);
            CHECK(transform.transformPoint(Vec3{4.0F, 5.0F, 6.0F}) == Vec3{5.0F, 7.0F, 9.0F});
            CHECK(transform.transformVector(Vec3{4.0F, 5.0F, 6.0F}) == Vec3{4.0F, 5.0F, 6.0F});
        }

        TEST_CASE("SE3 pure rotation matches SO3") {
            Vec<Scalar, 6> const tangent{0.0F, 0.0F, kHalfPi, 0.0F, 0.0F, 0.0F};
            SE3 const            transform = SE3::exp(tangent);
            SO3 const            rotation  = SO3::exp(Vec3{0.0F, 0.0F, kHalfPi});

            CHECK(isNearlyEqual(transform.rotation(), rotation));
            CHECK(transform.translation() == Vec3{});
            CHECK(isNearlyEqual(transform.transformPoint(Vec3{1.0F, 0.0F, 0.0F}), Vec3{0.0F, 1.0F, 0.0F}));
            CHECK(isNearlyEqual(transform.log(), tangent));
        }

        TEST_CASE("SE3 exp and log round trip mixed twists") {
            Vec<Scalar, 6> const tangent{0.2F, -0.3F, 0.4F, 1.0F, -2.0F, 3.0F};
            SE3 const            transform = SE3::exp(tangent);

            CHECK(isNearlyEqual(transform.log(), tangent));
            CHECK(isNearlyEqual(SE3::exp(transform.log()), transform));
        }

        TEST_CASE("SE3 composition and inverse work") {
            SE3 const    lhs = SE3::fromRotationTranslation(SO3::fromAxisAngle(Vec3{0.0F, 0.0F, 1.0F}, kHalfPi), Vec3{1.0F, 2.0F, 3.0F});
            SE3 const    rhs = SE3::fromRotationTranslation(SO3::fromAxisAngle(Vec3{1.0F, 0.0F, 0.0F}, kHalfPi), Vec3{4.0F, 5.0F, 6.0F});
            Vec3 const   point{7.0F, 8.0F, 9.0F};
            Scalar const epsilon = Scalar{8} * kEpsilon;

            CHECK(isNearlyEqual((lhs * rhs).transformPoint(point), lhs.transformPoint(rhs.transformPoint(point)), epsilon));
            CHECK(isNearlyEqual((lhs * lhs.inverse()).transformPoint(point), point, epsilon));
            CHECK(isNearlyEqual((lhs.inverse() * lhs).transformPoint(point), point, epsilon));
        }

        TEST_CASE("SE3 matrix form uses translation column with column vector multiplication") {
            SE3 const    transform = SE3::fromRotationTranslation(SO3::fromAxisAngle(Vec3{0.0F, 0.0F, 1.0F}, kHalfPi), Vec3{1.0F, 2.0F, 3.0F});
            Mat4x4 const matrix    = transform.toMat4();
            Vec4 const   point{4.0F, 5.0F, 6.0F, 1.0F};
            Vec4 const   result = matrix * point;

            CHECK(matrix(0, 3) == 1.0F);
            CHECK(matrix(1, 3) == 2.0F);
            CHECK(matrix(2, 3) == 3.0F);
            CHECK(matrix(3, 0) == 0.0F);
            CHECK(matrix(3, 1) == 0.0F);
            CHECK(matrix(3, 2) == 0.0F);
            CHECK(matrix(3, 3) == 1.0F);
            CHECK(isNearlyEqual(result, Vec4{-4.0F, 6.0F, 9.0F, 1.0F}));
        }

    } // namespace
} // namespace epsilon::math
