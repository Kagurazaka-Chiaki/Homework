/**
 *
**/


/**
 * Definition for a binary tree node.
**/

#include <cstdlib>

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

class Solution {

    bool is_leaf(struct TreeNode *root) {
        return root->left == nullptr && root->right == nullptr;
    }

    void dfs(TreeNode *parent, bool is_left, TreeNode *root) {
        if (nullptr == root) { return; }

        dfs(root, true, root->left);
        dfs(root, false, root->right);

        if (is_leaf(root) && 0 == root->val) {
            if (is_left) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        }
    }


  public:
    TreeNode *pruneTree(TreeNode *root) {
        TreeNode *vir = (TreeNode *) malloc(sizeof(TreeNode));
        vir->left = root;
        dfs(vir, true, root);
        return vir->left;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    return 0;
}
