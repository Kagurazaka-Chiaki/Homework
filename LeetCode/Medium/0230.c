/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int *k, int *ans) {
    if (root != NULL) { 
        dfs(root->left, k, ans);
        (*k)--;
        if (*k == 0) {
            *ans = root->val;
        }
        dfs(root->right, k, ans);
    }
}


int kthSmallest(struct TreeNode* root, int k){
    int ans = 0;
    dfs(root, &k, &ans);
    return ans;
}
