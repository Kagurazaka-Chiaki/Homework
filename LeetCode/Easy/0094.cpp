/**
 * @brief 94. 二叉树的中序遍历
 * 
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * 
**/

#include <iostream>
#include <algorithm>
#include <deque>

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
**/

class Solution {

    void dfs(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) { return; }
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        dfs(root, ans);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc; (void) argv;
    /* code */
    return 0;
}