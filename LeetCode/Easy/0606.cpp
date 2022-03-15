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

    bool is_leaf_node(TreeNode *root) {
        return root->left == nullptr && root->right == nullptr;
    }

    string dfs(TreeNode *root) {
        if (root == nullptr) { return ""; }
        string str_number = std::to_string(root->val);
        if (is_leaf_node(root)) {
            return str_number + "";
        } else if (root->right == nullptr) {
            return str_number + "(" + dfs(root->left) + ")";
        } else {  
            return str_number + "(" + dfs(root->left) + ")(" + dfs(root->right) + ")";
        }
    }

    string tree2str(TreeNode* root) {
        return dfs(root);
    }
};