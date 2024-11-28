// BM16 删除有序链表中重复的元素 只保留原链表中只出现一次的元素

#include "NowCoderTop101.hpp"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) { return nullptr; }
        if (head->next == nullptr) { return head; }
        if (head->next->next == nullptr) {
            if (head->val == head->next->val) {
                delete head->next;
                delete head;
                return nullptr;
            }
            return head;
        }
        auto const &dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *p1 = dummy;
        ListNode *p2 = head;

        while (p2 != nullptr && p2->next != nullptr) {
            if (p2->val == p2->next->val) {
                ListNode *flag = p2->next;
                while (flag != nullptr && flag->val == p2->val) {
                    ListNode *temp = flag;
                    flag = flag->next;
                    p2->next = flag;
                    delete temp;
                }
                p1->next = flag;
                p2 = flag;
            } else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return dummy->next;
    }
};