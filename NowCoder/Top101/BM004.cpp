#include "NowCoderTop101.hpp"

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        auto dummy = new ListNode(-1);
        auto curr = dummy;
        while (pHead1 && pHead2) {
            if (pHead1->val <= pHead2->val) {
                curr->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                curr->next = pHead2;
                pHead2 = pHead2->next;
            }
            curr = curr->next;
        }
        curr->next = pHead1 ? pHead1 : pHead2;
        return dummy->next;
    }
};