/**
 * @brief 222. 完全二叉树的节点个数
 * 
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) { return 0; }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    return 0;
}