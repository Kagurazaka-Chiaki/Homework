#include <catch2/catch_test_macros.hpp>
#include <epsilon-math01/vector/vec3_ops.hpp>

namespace epsilon::math {
    namespace {

        TEST_CASE("vec3 ops header exposes cross product directly") {
            CHECK(cross(Vec<float, 3>{1.0F, 0.0F, 0.0F}, Vec<float, 3>{0.0F, 1.0F, 0.0F}) == Vec<float, 3>{0.0F, 0.0F, 1.0F});
        }

    } // namespace
} // namespace epsilon::math
