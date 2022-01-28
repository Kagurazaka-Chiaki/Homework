/**
 *
**/


#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    std::vector<int> level_order(TreeNode *root) {

    }

    std::vector<std::vector<int>> levelOrder(TreeNode *root) {

    }

    std::vector<std::vector<int>> levelReOrder(TreeNode *root) {

    }
};


TreeNode *insert_tree_node(TreeNode *root, int value) {
    if (root == NULL) { return new TreeNode(value); }
    if (root->val > value) {
        root->left = insert_tree_node(root->left, value);
    } else if (root->val < value) {
        root->right = insert_tree_node(root->right, value);
    }
    return root;
}

TreeNode *build_tree() {
    TreeNode *result = nullptr;

    auto data = std::vector<std::string>{
        "3", "9", "20","null", "null", "15","7"
    };

    for (auto i : data) {
        if (i == "null") { continue; }
        int v = atoi(i.c_str());
        printf("insert [%d]\n", v);
        if (result == nullptr) {
            result = new TreeNode(v);
        } else {
            result = insert_tree_node(result, v);
        }
    }

    return result;
}



/**
 * Dot 语言打印树结构
**/
void DotPrint(TreeNode *root) {
    if (root != NULL) {
        printf("%d -> {", root->val);
        if (root->left != NULL) {
            printf(" %d", root->left->val);
        }
        printf(" ");
        if (root->right != NULL) {
            printf("%d ", root->right->val);
        }
    }
    printf("}\n");
}

void print_tree_node(TreeNode *node) {
    printf("%p -> {%p|%d|%p} --> ", node, node->left, node->val, node->right);
    printf("\n");
}

void DFS(TreeNode *root) {
    if (root == NULL) { return; }
    // PrintTreeNode(root);
    DFS(root->left);
    print_tree_node(root);
    // DotPrint(root);
    DFS(root->right);
    // PrintTreeNode(root);
}




int main(int argc, char const *argv[]) {
    /* code */
    (void) argc; (void) argv;

    auto s = new Solution();

    auto t = build_tree();

    DFS(t);

    return 0;
}