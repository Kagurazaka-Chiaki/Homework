/**
 * @brief 100. 相同的树
 * 
 * https://leetcode-cn.com/problems/same-tree/
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL || q == NULL) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}