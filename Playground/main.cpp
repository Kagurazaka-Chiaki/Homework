
#include <unordered_map>

#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <new>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

template<typename T>
void print_vector(std::vector<T> const &vec) {
    for (auto const &v: vec) {
        std::cout << "[" << v << "]";
    }
    std::cout << std::endl;
}

template<typename T>
void print_matrix(std::vector<std::vector<T>> const &mat) {
    std::cout << "[" << std::endl;
    for (auto const &m: mat) {
        print_vector(m);
    }
    std::cout << "]" << std::endl;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &vec) {
    os << "vec: " << "size: {" << vec.size() << "} ";
    for (auto const &v: vec) {
        os << "[" << v << "]";
    }
    return os << std::endl;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, std::pair<T, T> const &pair) {
    os << "pair: " << "{" << pair.first << ", " << pair.second << "}";
}

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &map) {
    auto all_key_vec = std::vector<K>(map.size());
    std::transform(map.begin(), map.end(), all_key_vec.begin(), [](auto const &pair) { return pair.first; });
    std::sort(all_key_vec.begin(), all_key_vec.end());
    std::cout << "map: " << "size: [" << map.size() << "]" << std::endl;
    for (auto const &key: all_key_vec) {
        std::cout << "[" << key << "]: " << map.at(key) << std::endl;
    }
}

auto get_curr_path(std::string const &folder_name) -> std::filesystem::path {
    auto bin_path = std::filesystem::current_path();
    auto build_path = bin_path.parent_path();
    auto project_path = build_path.parent_path();
    return project_path / folder_name;
}

int get_sum(std::vector<int> const &tree, int s, int t, int p, int l, int r) {
    if (l <= s && t <= r) {
        return tree[p];
    }
    int m = (s + t) / 2;
    int res = 0;
    if (l <= m) {
        res += get_sum(tree, s, m, 2 * p, l, r);
    }
    if (r > m) {
        res += get_sum(tree, m + 1, t, 2 * p + 1, l, r);
    }
    return res;
}

void build_tree(std::vector<int> &tree, std::vector<int>const &d, int s, int t, int p) {
    if (s == t) {
        tree[p] = d[s];
        return;
    }
    int m = (s + t) / 2;
    build_tree(tree, d, s, m, 2 * p);
    build_tree(tree, d, m + 1, t, 2 * p + 1);
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

namespace global {
    std::unordered_map<int, std::vector<std::vector<int>>> v = {};

    int ans = 0;

}

#include "GenMat.hpp"

void compute(std::fstream &fcin, std::fstream &fcout) {

    auto gm = math::GenMat<int>(2, 3);

    // 1 2 3
    // 4 5 6

    gm.swap_row(1, 2);

    gm.show_raw();

    gm.shift_row(1, 4);

    gm.show_raw();

    throw std::bad_alloc();
    std::cout << gm.get_num(1, 3) << std::endl;
    
}

int main() {
    auto playground_path = get_curr_path("Playground");

    // read the content of input.txt
    auto input_path = playground_path / "input.txt";
    std::fstream input_file(input_path, std::ios::in);

    if (!input_file.is_open()) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return EXIT_FAILURE;
    }

    // create a output.txt file
    auto output_path = playground_path / "output.txt";
    std::fstream output_file(output_path, std::ios::out | std::ios::trunc);

    if (!output_file.is_open()) {
        std::cerr << "Failed to open output.txt" << std::endl;
        return EXIT_FAILURE;
    }

    compute(input_file, output_file);

    input_file.close();
    output_file.close();
    return EXIT_SUCCESS;
}