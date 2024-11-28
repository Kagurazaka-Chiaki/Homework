// 链表中倒数第 k 个结点


#include "NowCoderTop101.hpp"

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k) {
        if (pHead == nullptr) { return nullptr; }
        int n = 0;
        ListNode *p1 = pHead;
        while (p1 != nullptr) {
            p1 = p1->next;
            ++n;
        }
        if (k > n) { return nullptr; }
        if (k == n) { return pHead; }
        p1 = pHead;
        for (int i = 0; i < k; ++i) {
            if (p1 != nullptr && p1->next != nullptr) {
                p1 = p1->next;
            }
        }
        ListNode *p2 = pHead;
        while (p1 != nullptr) {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p2;
    }
};
