// 判断链表是否有环

#include "NowCoderTop101.hpp"

class Solution {
  public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) { return false; }
        ListNode *p1 = head;
        ListNode *p2 = head;
        while (p1 != nullptr && p1->next != nullptr) {
            p1 = p1->next->next;
            p2 = p2->next;
            if (p1 == p2) {
                return true;
            }
        }
        return false;
    }
};
