// BM13 判断一个链表是否为回文结构

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

    ListNode *Reverse(ListNode *head) {
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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return true; }
        int n = Length(head);
        if (n % 2 == 0) {
            ListNode *p1 = head;
            for (int i = 0; i < (n / 2) - 1; ++i) {
                p1 = p1->next;
            }
            ListNode *flag = p1->next;
            ListNode *p2 = p1->next;
            p1->next = nullptr;
            ListNode *r = Reverse(head);
            while (r != nullptr || p2 != nullptr) {
                if (r->val != p2->val) { return false; }
                r = r->next;
                p2 = p2->next;
            }
            p1->next = flag;
        } else {
            ListNode *p1 = head;
            for (int i = 0; i < (n / 2) - 1; ++i) {
                p1 = p1->next;
            }
            ListNode *mid = p1->next;
            ListNode *p2 = mid->next;
            p1->next = nullptr;
            ListNode *r = Reverse(head);
            while (r != nullptr || p2 != nullptr) {
                if (r->val != p2->val) { return false; }
                r = r->next;
                p2 = p2->next;
            }
            p1->next = mid;
        }
        return true;
    }
};