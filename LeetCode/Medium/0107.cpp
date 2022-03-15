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
 */
class Solution {
    queue<TreeNode*> que;
    unordered_map <TreeNode *, int> dep;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) { return ret; }
        while (!que.empty()) { que.pop(); }

        que.push(root);
        dep[root] = 0;
        int pre_depth = -1;
        while (!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();

            int depth = dep[temp];

            if (depth != pre_depth) {
                vector<int> v;
                ret.push_back(v);
            }
            pre_depth = depth;
            ret[ret.size() - 1].push_back(temp->val);

            if (temp->left) {
                que.push(temp->left);
                dep[temp->left] = dep[temp] + 1;
            }
            if (temp->right) {
                que.push(temp->right);
                dep[temp->right] = dep[temp] + 1;
            }
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};