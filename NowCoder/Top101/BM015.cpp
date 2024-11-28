// BM15 删除有序链表中重复的元素 - 使链表中的所有元素都只出现一次

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
                ListNode *flag = head->next;
                head->next = nullptr;
                delete flag;
            }
            return head;
        }
        ListNode *p1 = head;
        while (p1->next != nullptr) {
            if (p1->val == p1->next->val) {
                ListNode *flag = p1->next;
                p1->next = p1->next->next;
                delete flag;
            } else {
                p1 = p1->next;
            }
        }
        return head;
    }
};