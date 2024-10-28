
#ifndef PATHFINDING_HPP
#define PATHFINDING_HPP

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

namespace PF {

    struct node {
        int x, y;

        bool is_wall;

        std::vector<node *> neighbor_vec;

        node *parent;

        int g_cost;

        int h_cost;

        int f_cost() const {
            return g_cost + h_cost;
        }
    };

    class map {

        int width = 0;

        int height = 0;

        std::vector<std::vector<std::unique_ptr<node>>> data;

      public:
        map(int width, int height)
            : width(width), height(height) {
            for (int i = 0; i < height; ++i) {
                std::vector<std::unique_ptr<node>> row = {};
                for (int j = 0; j < width; ++j) {
                    row.push_back(std::make_unique<node>(
                        node{j, i, false, {}, nullptr, 0, 0}
                    ));
                }
                data.push_back(std::move(row));
            }
        }

        map(std::initializer_list<std::string> const init_lit) {
            height = init_lit.size();
            width = init_lit.begin()->size();
            for (int i = 0; i < height; ++i) {
                std::vector<std::unique_ptr<node>> row = {};
                for (int j = 0; j < width; ++j) {
                    row.push_back(std::make_unique<node>(
                        node{j, i, init_lit.begin()[i][j] == '#', {}, nullptr, 0, 0}
                    ));
                }
                data.push_back(std::move(row));
            }
        }

        map(map const &) = delete;
        auto operator=(map const &) -> map & = delete;
        map(map &&) noexcept = default;
        auto operator=(map &&) noexcept -> map & = default;

        ~map() noexcept = default;

        void set_start(int x, int y);

        void set_end(int x, int y);

        void add_wall(int x, int y);

        void remove_wall(int x, int y);

        void clear_all_wall();

        void find_path();

        void print_path() const;

        void print_grid() const;
    };

} // namespace PF


#endif // PATHFINDING_HPP