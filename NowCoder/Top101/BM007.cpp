// 链表中环的入口结点


#include "NowCoderTop101.hpp"

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
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
};
