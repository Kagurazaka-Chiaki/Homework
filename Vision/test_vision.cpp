

#include <catch2/catch_test_macros.hpp>

#include "image.hpp"


TEST_CASE("test vision") {
   
   
    SECTION("001") {

        auto a = Image("gale.png");
        a.write_to_file("gale_copy.png");
        auto b = Image("gale_copy.png");
        for (int i = 0; i < a.size; ++i) {
            CHECK(a.data[i] == b.data[i]);
        }

    }




}