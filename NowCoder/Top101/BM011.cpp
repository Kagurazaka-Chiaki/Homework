// BM11 链表相加 (二)

#include "NowCoderTop101.hpp"

class Solution {
public:
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        ListNode *p1 = reverse(head1);
        ListNode *p2 = reverse(head2);
        auto const &dummy = new ListNode(0);
        ListNode *q = dummy;
        int t = 0;
        while (p1 != nullptr || p2 != nullptr) {
            int a = p1 != nullptr ? p1->val : 0;
            int b = p2 != nullptr ? p2->val : 0;
            t = a + b + t;
            q->next = new ListNode(t % 10);
            t /= 10;
            q = q->next;
            if (p1 != nullptr) { p1 = p1->next; }
            if (p2 != nullptr) { p2 = p2->next; }
        }
        if (t > 0) {
            q->next = new ListNode(t);
        }
        return reverse(dummy->next);
    }
};