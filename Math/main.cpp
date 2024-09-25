
#include "geometry.hpp"
#include "vec.hpp"

#include <cstdlib>
#include <iostream>

int main() {

    std::cout << "Hello, World!" << std::endl;

    auto p1 = math::point<3>{1, 2, 3};
    auto p2 = math::point<3>{1, 2, 3};
    auto p3 = math::point<3>{1, 2, 3};

    // distance
    std::cout << "Distance: " << math::distance(p1, p2) << std::endl;
    std::cout << "Triangle Area: " << math::triangle_area(p1, p2, p3) << std::endl;

    auto p34 = math::point<4>{0, 0, 0};
    auto p35 = math::point<4>{2, 0, 0};
    auto p36 = math::point<4>{
            1.754806155676498, -2.558013688392027, 2.712391940730655, 0
    };

    std::cout << "Distance: " << math::distance(p34, p35) << std::endl;
    try {
        std::cout << "Triangle Area: " << math::triangle_area(p34, p35, p36) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    math::triangle t1{
            {0,                 0,                  0                 },
            {2.752631535015455, 3.81220908497157,   -3.160394755084511},
            {5.052341847754612, -4.561236070691592, 1.7580024991465   }
    };

    auto const &p = math::vec<3>{1, 2, 3};

    auto b = math::is_project_in_triangle(p, t1);

    std::cout << "Is Project In Triangle: " << b << std::endl;

    return EXIT_SUCCESS;
}