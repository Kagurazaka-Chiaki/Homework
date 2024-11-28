// BM10 两个链表的第一个公共结点

#include "NowCoderTop101.hpp"

class Solution {

    ListNode *EntryNodeOfLoop(ListNode *pHead) {
        if (pHead == nullptr) { return nullptr; }
        ListNode *p1 = pHead;
        ListNode *p2 = pHead;
        bool flag = false;
        while (p1 != nullptr && p1->next != nullptr) {
            p1 = p1->next->next;
            p2 = p2->next;
            if (p1 == p2) {
                flag = true;
                break;
            }
        }
        if (flag) {
            int n = 1;
            p2 = p1->next;
            while (p2 != p1) {
                p2 = p2->next;
                ++n;
            }
            p1 = pHead;
            p2 = pHead;
            for (int i = 0; i < n; ++i) {
                p2 = p2->next;
            }
            while (p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
        return nullptr;
    }

  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr) { return nullptr; }
        int n = 1;
        ListNode *p1 = pHead1;
        while (p1->next != nullptr) {
            p1 = p1->next;
            ++n;
        }
        p1->next = pHead2;
        ListNode *ans = EntryNodeOfLoop(pHead1);
        p1->next = nullptr;
        return ans;
    }
};
