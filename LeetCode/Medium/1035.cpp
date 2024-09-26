/**
 * @brief 1305. 两棵二叉搜索树中的所有元素
 * 
 * https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/
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
    static int const INF = 0x3f3f3f3f;

  public:
    void dfs(TreeNode *root, vector<int> &list) {
        if (root == nullptr) { return; }
        dfs(root->left, list);
        list.push_back(root->val);
        dfs(root->right, list);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> ans;
        vector<int> l1, l2;
        dfs(root1, l1);
        dfs(root2, l2);
        int n = l1.size(), m = l2.size(), i = 0, j = 0;
        while (i < n || j < m) {
            int a = i < n ? l1[i] : INF;
            int b = j < m ? l2[j] : INF;
            if (a <= b) {
                ans.push_back(a);
                i++;
            } else {
                ans.push_back(b);
                j++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */
    return 0;
}