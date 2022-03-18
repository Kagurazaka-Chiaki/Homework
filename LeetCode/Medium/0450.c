/**
 * @brief 450. 删除二叉搜索树中的节点
 * 
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *FindMin(struct TreeNode *Root) {
    if (Root == NULL) { return NULL; }
    if (Root->left != NULL) {
        return FindMin(Root->left);
    } else {
        return Root;
    }
}

struct TreeNode *deleteNode(struct TreeNode *root, int key) {
    if (root == NULL) { return NULL; }
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL || root->right == NULL) {
            struct TreeNode *del = root;
            if (root->left == NULL) {
                root = root->right;
            } else {
                root = root->left;
            }
            // root = (root->right == NULL) ? root->left : root->right;
            free(del);
        } else {
            struct TreeNode *temp = root->right;
            temp = FindMin(temp);
            root->val = temp->val;
            root->right = deleteNode(root->right, root->val);
        }
    }
    return root;
}