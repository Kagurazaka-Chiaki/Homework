/**
 * @brief LCP 44. 开幕式焰火
 *
 * https://leetcode-cn.com/problems/sZ59z6/
 * 
**/


#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
        : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<int, int> hash;

    void transfer(struct TreeNode *root) {
        if (root == nullptr) { return; }
        hash[root->val] = 1;
        transfer(root->left);
        transfer(root->right);
    }

  public:
    int numColor(TreeNode *root) {
        int result = 0;
        transfer(root);
        for (auto iter = hash.begin(); iter != hash.end(); iter++) {
            if (iter->first) { result++; }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    return 0;
}