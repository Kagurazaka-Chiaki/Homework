/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {

    unordered_map<Node*, int> depth;
    queue<Node *> que; 

public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        result.clear();
        if (root == NULL) { return result;}
        while(!que.empty()) { que.pop(); }

        que.push(root);
        while (!que.empty()) {
            Node *temp = que.front();
            que.pop();

            if (depth[temp] >= result.size()) {
                result.push_back({temp->val});
            } else {
                result[depth[temp]].push_back(temp->val);
            }

            for (Node *item : temp->children) {
                que.push(item);
                depth[item] = depth[temp] + 1;
            }
        }

        return result;
    }
};


