/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX ((int) 1e5)

typedef struct {
    struct TreeNode *root;
    int hash[MAX];
} FindElements;


void dfs(FindElements *obj, struct TreeNode **cp, struct TreeNode *root, int value) {
    if (root == NULL) { *cp = NULL; return; }
    *cp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    (*cp)->val = value;
    if (value <= MAX) { obj->hash[value] = 1; }
    dfs(obj, &((*cp)->left), root->left, 2 * value + 1);
    dfs(obj, &((*cp)->right), root->right, 2 * value + 2);
}

FindElements* findElementsCreate(struct TreeNode* root) {
    FindElements *obj = (FindElements *)malloc(sizeof(FindElements));
    memset(obj->hash, 0, sizeof(obj->hash));
    dfs(obj, &obj->root, root, 0);
    return obj;
}

// bool dfs(struct TreeNode *root, int target) {
//     if (root == NULL) { return false; }
// } 

bool findElementsFind(FindElements* obj, int target) {
    return obj->hash[target];
}

void findElementsFree(FindElements* obj) {
    free(obj);
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 
 * findElementsFree(obj);
*/