/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool Check(struct TreeNode *A, struct TreeNode *B) {
    if (A == NULL && B == NULL) { return true; }
    if (A == NULL || B == NULL) { return false; }
    return A->val == B->val && Check(A->left, B->right) && Check(A->right, B->left);
}


bool isSymmetric(struct TreeNode *root){
    if (root == NULL) {
        return true;
    } else {
        return Check(root->left, root->right);
    }
}
