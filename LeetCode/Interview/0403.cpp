/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
    vector<ListNode *> ret;
    vector<ListNode *> pre;

  public:
    int get_depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return max(get_depth(root->left), get_depth(root->right)) + 1;
    }

    void dfs(TreeNode *root, int depth) {
        if (root == nullptr) { return; }
        if (pre[depth] == nullptr) {
            ret[depth] = new ListNode(root->val);
            pre[depth] = ret[depth];
        } else {
            pre[depth]->next = new ListNode(root->val);
            pre[depth] = pre[depth]->next;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    vector<ListNode *> listOfDepth(TreeNode *tree) {
        int dep = get_depth(tree);
        ret.clear();
        pre.clear();
        for (int i = 0; i < dep; i++) {
            ret.push_back(nullptr);
            pre.push_back(nullptr);
        }
        dfs(tree, 0);
        return ret;
    }
};