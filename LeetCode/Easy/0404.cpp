/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool is_leaf_node(TreeNode *node) {
        return (node->left == nullptr) && (node->right == nullptr);
    }

    int dfs(TreeNode *node, bool is_leaf) {
        if (node == nullptr) { return 0; }

        if (is_leaf_node(node) == true && is_leaf) {
            return node->val;
        }

        return dfs(node->left, true) + dfs(node->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};