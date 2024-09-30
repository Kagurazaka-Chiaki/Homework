#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP


#include <initializer_list>
#include <type_traits>
#include <iostream>
#include <vector>

namespace Tree {


    // template<typename T>
    // class SegmentTree {};
    // // enable_if_t<std::is_arithmetic_v<T>, T> {

    template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    class SegmentTree {

      private:
        // 线段树的空间：
        //
        // 如果采用堆式存储 `(p->left = 2p, p->right = 2p + 1)`
        // `n` 个叶子节点，最大范围为 `pow(2, ceil(log(n) + 1))`
        //
        // 分析:
        //
        // 深度为 `ceil(log2(n))`, 完全二叉树的节点数为 `pow(2, ceil(log2(n) + 1)) - 1`
        // `max(pow(2, ceil(log2(n) + 1)) - 1 / n)` 在 `n = pow(2, k) + 1` 时会取到最大值;
        // 此时节点数为 `pow(2, ceil(log2(pow(2, k) + 1) + 1)) - 1 = pow(2, k + 2) - 1 = 4n - 5`
        std::vector<T> tree;

        // 原始数据
        std::vector<T> data;

        // [s, t] 为当前节点区间, p 为当前节点编号
        auto build_tree(int s, int t, int p) {
            if (s == t) {
                tree[p] = data[s];
                return;
            }
            int m = (s + t) / 2;
            build_tree(s, m, p * 2);
            build_tree(m + 1, t, p * 2 + 1);
            tree[p] = tree[p * 2] + tree[p * 2 + 1];
        }

        // [l, r] 为查询区间, [s, t] 为当前节点区间, p 为当前节点编号
        auto get_sum(int s, int t, int p, int l, int r) -> T {
            if (l <= s && t <= r) {
                // 当前节点区间完全包含查询区间
                return tree[p];
            }
            int m = s + ((t - s) >> 1);
            T res = 0;
            if (l <= m) {
                // 查询区间与左子树区间有交集
                res += get_sum(s, m, p * 2, l, r);
            }
            if (r > m) {
                // 查询区间与右子树区间有交集
                res += get_sum(m + 1, t, p * 2 + 1, l, r);
            }
            return res;
        }

      public:
        explicit SegmentTree(std::initializer_list<T> const &init_list) {
            data = std::vector<T>(init_list);
            tree = std::vector<T>(data.size() * 4); // 4n - 5 < 4n
            build_tree(0, data.size() - 1, 1);
        }

        explicit SegmentTree(std::vector<T> const &vec) {
            data = vec;
            tree = std::vector<T>(data.size() * 4); // 4n - 5 < 4n
            build_tree(0, data.size() - 1, 1);
        }

        auto get(int l, int r) -> T {
            return get_sum(0, data.size() - 1, 1, l, r);
        }

        auto print() -> void {
            for (auto const &v: tree) {
                std::cout << "[" << v << "]";
            }
            std::cout << std::endl;
        }

        auto update(int i, T val) -> void {
            // TODO: 更新操作
        }
    };


} // namespace Tree


#endif // SEGMENT_TREE_HPP