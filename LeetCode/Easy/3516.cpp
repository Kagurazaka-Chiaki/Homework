/**
 * @file 3516.cpp
 * @brief https://leetcode.cn/problems/find-closest-person
**/


#include <array>
#include <cmath>
#include <utility>

template<std::size_t N, std::size_t J, std::size_t... I>
constexpr std::array<int8_t, N + 1> row(std::index_sequence<I...>) {
    return {
        (int8_t) ((int) I - (int) J)...
    };
}

template<std::size_t N, std::size_t... J>
constexpr std::array<std::array<int8_t, N + 1>, N + 1> table(std::index_sequence<J...>) {
    return {
        row<N, J>(std::make_index_sequence<N + 1>{})...
    };
}

template<std::size_t N>
struct T {
    static constexpr auto diff = table<N>(std::make_index_sequence<N + 1>{});

    static constexpr auto abs = [] {
        std::array<std::array<int8_t, N + 1>, N + 1> t{};
        for (auto i = 0; i < N + 1; ++i) {
            for (auto j = 0; j < N + 1; ++j) {
                auto v  = (int) i - (int) j;
                t[i][j] = (int8_t) (v < 0 ? -v : v);
            }
        }
        return t;
    }();
};

class Solution {
  public:
    int findClosest(int x, int y, int z) {
        if (x >= 100 || y >= 100 || z >= 100) {
            if (std::abs(z - x) == std::abs(z - y)) {
                return 0;
            } else {
                return std::abs(z - x) < std::abs(z - y) ? 1 : 2;
            }
        } else {
            if (T<100>::abs[z][x] == T<100>::abs[z][y]) {
                return 0;
            } else {
                return T<100>::abs[z][x] < T<100>::abs[z][y] ? 1 : 2;
            }
        }
    }
};
