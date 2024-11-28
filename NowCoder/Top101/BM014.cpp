// BM14 链表的奇偶重排


#include "NowCoderTop101.hpp"

class Solution {
public:

    int Length(ListNode *head) {
        int n = 0;
        ListNode *p1 = head;
        while (p1 != nullptr) {
            p1 = p1->next;
            ++n;
        }
        return n;
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return head; }
        if (head->next->next == nullptr) { return head; }
        int n = Length(head);
        
        auto const &d1 = new ListNode(0);
        ListNode *pd1 = d1;
        auto const &d2 = new ListNode(0);
        ListNode *pd2 = d2;

        ListNode *p = head;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                pd1->next = p;
                pd1 = pd1->next;
            } else {
                pd2->next = p;
                pd2 = pd2->next;
            }
            p = p->next;
        }
        pd2->next = nullptr;
        pd1->next = d2->next;
        return d1->next;
    }
};