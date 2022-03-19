/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
**/

bool is_leaf(struct TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

void dfs(struct TreeNode* parent, bool is_left, struct TreeNode* root, int target) {
    if (root == NULL) { return; }
    dfs(root, true,  root->left,  target);
    dfs(root, false, root->right, target);
    if (is_leaf(root) && root->val == target) {
        if (is_left == true) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }
}

struct TreeNode* removeLeafNodes(struct TreeNode* root, int target){
    if (root == NULL) { return NULL; }
    struct TreeNode *vir = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    vir->left = root;
    dfs(vir, true, root, target);
    return vir->left;
}
