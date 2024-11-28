// BM12 单链表的排序

#include "NowCoderTop101.hpp"

// merge sort
class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
  public:
    ListNode *sortInList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto slow = head;
        auto fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto right = sortInList(slow->next);
        slow->next = nullptr;
        auto left = sortInList(head);
        auto dummy = new ListNode(-1);
        auto curr = dummy;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        curr->next = left ? left : right;
        return dummy->next;
    }
};
