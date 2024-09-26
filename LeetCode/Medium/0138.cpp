/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) { return nullptr; }
        Node *ret_head = new Node(head->val);
        Node *head2 = ret_head;
        Node *pre_head = head->next;
        while (pre_head) {
            ret_head->next = new Node(pre_head->val);
            pre_head = pre_head->next;
            ret_head = ret_head->next;
        }

        pre_head = head, ret_head = head2;
        while (pre_head) {
            Node *target = pre_head->random;
            Node *go = head;
            int cnt = 0;
            while (go != target) {
                go = go->next;
                ++cnt;
            }

            go = head2;
            while (cnt) {
                go = go->next;
                --cnt;
            }
            ret_head->random = go;

            pre_head = pre_head->next;
            ret_head = ret_head->next;
        }

        return head2;
    }
};