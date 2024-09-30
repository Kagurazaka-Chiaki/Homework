//   Definition for a binary tree node.

#include <unordered_map>

#include <algorithm>
#include <iostream>
#include <vector>

struct TreeNode {
    int val;

    TreeNode *left;
    TreeNode *right;

    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode()
        : val(0), next(nullptr) {}

    ListNode(int x)
        : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next)
        : val(x), next(next) {}
};

namespace help {

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

} // namespace help