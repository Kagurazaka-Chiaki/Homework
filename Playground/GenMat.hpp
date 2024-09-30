#ifndef GENMAT_HPP
#define GENMAT_HPP

#include <type_traits>
#include <unordered_map>

#include <iostream>
#include <vector>

namespace math {

    template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    class GenMat {

        int row;
        int col;
        std::unordered_map<int, std::vector<T>> map = {};

        // 生成函数
        auto func(int n, int m, int i, int j) -> T {
            return T(((i + 1) - 1) * m + (j + 1));
        }

      public:
        GenMat(int row, int col)
            : row(row), col(col) {
            for (int i = 0; i < row; i++) {
                if (map.find(i) == map.end()) {
                    map[i] = std::vector<T>(2, 0);
                    map[i][0] = func(row, col, i, 0);
                    map[i][1] = 0; // offset
                }
            }
        }

        auto swap_row(int x, int y) -> void {
            std::swap(this->map[x - 1], this->map[y - 1]);
        }

        auto shift_row(int x, int y) -> void { // TODO: 错误 - 优化
            this->map[x - 1][1] = -y; // offset
            auto ori = func(row, col, x, y) % col;
            std::cout << "Ori: " << ori << std::endl;
            this->map[x - 1][0] = func(row, col, x, y);
        }

        auto get_num(int x, int y) -> T {
            auto o = this->map[x - 1][1];
            auto h = this->map[x - 1][0];
            
            int k = 0;
            if (o < 0) {
                // k = o mod col
                k = col + o % col;
            } else {
                k = o % col;
            }

            auto p = ((x + 1) - 1) * col + (y + 1);
            std::cout << "o: " << o << " k: " << k << " p: " << p << std::endl;
            return p - k;
        }

        auto show_raw() -> void {
            std::cout << "Map: " << std::endl;
            for (int i = 0; i < row; i++) {
                std::cout << "Row " << i + 1 << ": ";
                std::cout << "Head: " << this->map[i][0] << " Offset: " << this->map[i][1] << " ";
                std::cout << std::endl;
            }
        
        }

        // auto show_all() -> void {
            
            
        // }
    };

} // namespace math


#endif // GENMAT_HPP