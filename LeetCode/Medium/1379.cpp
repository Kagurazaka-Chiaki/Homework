/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        TreeNode *left, *right;
        if (original == nullptr) { return nullptr; }
        if (target == original) { return cloned; }

        if (original->left) {
            left = getTargetCopy(original->left, cloned->left, target);
            if (left != nullptr) { return left; }
        }
        if (original->right) {
            right = getTargetCopy(original->right, cloned->right, target);
            if (right != nullptr) { return right; }
        }
        return nullptr;
    }
};
