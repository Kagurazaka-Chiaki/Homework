/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int Max(int a, int b) {
    return (a > b) ? a : b;
}

int maxDepth(struct TreeNode* root){
    if (root == NULL) { return 0; }
    // int left = maxDepth(root->left);
    // int right = maxDepth(root->right);
    // return 1 + ((left > right) ? left : right);
    return Max(maxDepth(root->left), maxDepth(root->right)) + 1;
}