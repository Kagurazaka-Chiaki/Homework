
#include <array>
#include <iostream>
#include <vector>

struct QuadTreeNode {
    int  depth;
    bool is_leaf;
    int  x1, y1;
    int  x2, y2;
    //
    std::array<QuadTreeNode *, 4> children;

    QuadTreeNode(int x1, int y1, int x2, int y2)
        : x1(x1), y1(y1), x2(x2), y2(y2) {
    }

    bool in_range(int target, std::vector<std::vector<int>> const &array) {
        return target >= array[this->x1][this->y1] && target <= array[this->x2][this->y2];
    }

    friend auto operator<<(std::ostream &os, const QuadTreeNode &node) -> std::ostream & {
        return os << "QuadTreeNode(" << node.x1 << ", " << node.y1 << ", "
                  << node.x2 << ", " << node.y2 << ")";
    }
};

bool search(QuadTreeNode *node, int target, std::vector<std::vector<int>> const &array) {
    if (not node->in_range(target, array)) {
        node->is_leaf = true;
        node->children.fill(nullptr);
        return false;
    }

    int x = (node->x1 + node->x2) / 2;
    int y = (node->y1 + node->y2) / 2;

    auto NW = QuadTreeNode(node->x1, node->y1, x, y);
    auto NE = QuadTreeNode(x, node->y1, node->x2, y);
    auto SE = QuadTreeNode(x, y, node->x2, node->y2);
    auto SW = QuadTreeNode(node->x1, y, x, node->y2);

    node->children = {&NW, &NE, &SE, &SW};

    for (auto &child: node->children) {
        child->depth   = node->depth + 1;
        child->is_leaf = (child->x2 - child->x1 <= 1) && (child->y2 - child->y1 <= 1);
    }

    if (node->is_leaf) {
        return node->in_range(target, array) &&
               (array[node->x1][node->y1] == target ||
                array[node->x2][node->y2] == target ||
                array[node->x1][node->y2] == target ||
                array[node->x2][node->y1] == target);
    }

    for (auto &child: node->children) {
        if (search(child, target, array)) {
            return true;
        }
    }

    return false;
}

int main() {
    // 7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
    // std::vector<std::vector<int>> array = {
    //     { 1,  2,  3,  4},
    //     { 5,  6,  7,  8},
    //     { 9, 10, 11, 12},
    //     {13, 14, 15, 16}
    // };

    // 5, [[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
    std::vector<std::vector<int>> array = {
        {1, 2,  8,  9},
        {2, 4,  9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };

    QuadTreeNode root(0, 0, 3, 3);
    root.is_leaf = false;

    int  target = 5;
    bool found  = search(&root, target, array);

    if (found) {
        std::cout << "Target " << target << " found in the quadtree." << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the quadtree." << std::endl;
    }

    return 0;
}