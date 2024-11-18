// 链表中的节点每 k 个一组翻转

#include "NowCoderTop101.hpp"

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto pre = dummy;
        auto cur = head;
        int i = 0;
        while (cur != nullptr) {
            ++i;
            if (i % k == 0) {
                pre = reverse(pre, cur->next);
                cur = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }

    ListNode *reverse(ListNode *pre, ListNode *next) {
        auto last = pre->next;
        auto cur = last->next;
        while (cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
};
