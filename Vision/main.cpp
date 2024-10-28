
#include "image.hpp"

#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

auto get_curr_path(std::string const &folder_name) -> std::filesystem::path {
    auto bin_path = std::filesystem::current_path();
    auto build_path = bin_path.parent_path();
    auto project_path = build_path.parent_path();
    return project_path / folder_name;
}

int main() {
    auto vision_path = get_curr_path("Vision");

    // auto image_path = vision_path / "circle.png";
    // std::cout << image_path << std::endl;

    // std::string a = image_path.generic_string();
    // auto a_cstr = a.c_str();
    // std::cout << a_cstr << std::endl;

    auto grayscale_values = std::vector<std::vector<int>>(
        {
            {0, 3, 0, 3, 0, 1, 2, 3},
            {0, 2, 0, 2, 0, 1, 2, 3},
            {0, 0, 1, 0, 0, 1, 2, 0},
            {0, 3, 0, 3, 0, 1, 2, 0},
            {0, 2, 0, 2, 0, 2, 2, 0},
            {0, 4, 0, 4, 0, 2, 1, 0},
            {0, 2, 0, 2, 0, 2, 1, 3},
            {0, 2, 0, 2, 0, 2, 1, 3},
        }
    );

    auto I = Image(grayscale_values);

    auto V = I.show({0, 0}, {8, 8}, 0);


    auto output_path = vision_path / "output.txt";
    std::fstream output_file(output_path, std::ios::out | std::ios::trunc);

    for (auto const &row : V) {
        for (auto const &pixel : row) {
            output_file << std::setw(3) << pixel << " ";
        }
        output_file << std::endl;
    }

    I.write_to_file("output.png");

    auto a = I.height_map_to_vertex(1000);

    for (auto const &v : a) {
        std::cout << v << std::endl;
    }
}
