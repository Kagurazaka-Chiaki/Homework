

/**
 *
**/


#include <initializer_list>

#include <cstdio>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>


enum class Instruction {
    LEFT,
    RIGHT,
    RESET,
    SET
};

struct BiTreeNode {
    int val;

    std::unique_ptr<BiTreeNode> left;

    std::unique_ptr<BiTreeNode> right;

    BiTreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
};

class BiTree {
  private:
  public:
    BiTreeNode *curr;
    std::unique_ptr<BiTreeNode> root;

    BiTree()
        : root(nullptr), curr(nullptr) {}

    BiTree(int val)
        : root(std::make_unique<BiTreeNode>(val)) {
        curr = root.get();
    }

    BiTree(std::initializer_list<int> list) {
        for (auto &val: list) {
            insert(val);
        }
        curr = root.get();
    }

    auto insert(int val) -> void {
        if (root == nullptr) {
            root = std::make_unique<BiTreeNode>(val);
            return;
        }

        auto current = root.get();
        while (current != nullptr) {
            if (val < current->val) {
                if (current->left == nullptr) {
                    current->left = std::make_unique<BiTreeNode>(val);
                    return;
                }
                current = current->left.get();
            } else {
                if (current->right == nullptr) {
                    current->right = std::make_unique<BiTreeNode>(val);
                    return;
                }
                current = current->right.get();
            }
        }
    }

    ~BiTree() {
        root.reset();
    }

    auto dfs_sum(BiTreeNode *node) -> std::pair<int, int> {
        if (node == nullptr) {
            return {0, 0};
        }

        auto left = dfs_sum(node->left.get());
        auto right = dfs_sum(node->right.get());

        return {left.first + right.first + node->val, left.second + right.second + 1};
    }

    auto dfs(BiTreeNode *node) -> void {
        if (node == nullptr) {
            return;
        }

        DotPrint(node);
        dfs(node->left.get());
        dfs(node->right.get());
    }

    void DotPrint(struct BiTreeNode *TreeNode) {
        if (TreeNode != NULL) {
            printf("%d -> {", TreeNode->val);
            if (TreeNode->left != NULL) {
                printf(" %d", TreeNode->left->val);
            }
            printf(" ");
            if (TreeNode->right != NULL) {
                printf("%d ", TreeNode->right->val);
            }
        }
        printf("}\n");
    }
};

auto print_tree_to_markdown(BiTree &tree) -> void {
    std::cout << "```dot" << std::endl;

    std::cout << "digraph G {" << std::endl;

    tree.dfs(tree.root.get());

    std::cout << "}" << std::endl;

    std::cout << "```" << std::endl;
}

auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;
    /* code */

    BiTree temp_tree = {5, 3, 7, 2, 4, 6, 8};

    temp_tree.dfs(temp_tree.root.get());

    std::cout << "Hello, Binary Tree!" << std::endl;


    // [Set(75), Left, Set(33), Reset, Right, Set(67), Left, Set(25)]
    std::vector<Instruction> instructions = {
            Instruction::SET,
            Instruction::LEFT,
            Instruction::SET,
            Instruction::RESET,
            Instruction::RIGHT,
            Instruction::SET,
            Instruction::LEFT,
            Instruction::SET
    };
    std::vector<int> values = {75, 33, 67, 25};
    int p = -1;

    BiTree tree = {0};

    for (auto &instruction: instructions) {
        print_tree_to_markdown(tree);
        printf("-------------\n");
        switch (instruction) {
            case Instruction::LEFT:
                if (tree.curr->left != nullptr) {
                    tree.curr = tree.curr->left.get();
                } else {
                    tree.curr->left = std::make_unique<BiTreeNode>(0);
                    tree.curr = tree.curr->left.get();
                }
                break;
            case Instruction::RIGHT:
                if (tree.curr->right != nullptr) {
                    tree.curr = tree.curr->right.get();
                } else {
                    tree.curr->right = std::make_unique<BiTreeNode>(0);
                    tree.curr = tree.curr->right.get();
                }
                break;
            case Instruction::RESET:
                tree.curr = tree.root.get();
                break;
            case Instruction::SET:
                tree.curr->val = values[++p];
                break;
        }
    }

    print_tree_to_markdown(tree);

    std::cout << "Sum: " << tree.dfs_sum(tree.root.get()).first << std::endl;
    std::cout << "Count: " << tree.dfs_sum(tree.root.get()).second << std::endl;

    return 0;
}
