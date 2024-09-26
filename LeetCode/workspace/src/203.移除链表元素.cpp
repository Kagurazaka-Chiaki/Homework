/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode.cn/problems/remove-linked-list-elements/description/
 *
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


#include "LeetCode.hpp"

#include <memory>

class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        // ListNode* dummy = new ListNode(0, head);
        // ListNode* cur = dummy;
        // while (cur->next) {
        //     if (cur->next->val == val) {
        //         ListNode* tmp = cur->next;
        //         cur->next = cur->next->next;
        //         delete tmp;
        //     } else {
        //         cur = cur->next;
        //     }
        // }
        // head = dummy->next;
        // delete dummy;
        // return head;
        auto dummy = std::make_unique<ListNode>(0, head);
        auto cur = dummy.get();
        while (cur->next) {
            if (cur->next->val == val) {
                auto tmp = cur->next;
                cur->next = cur->next->next;
                // delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummy->next;
        // delete dummy;
        return head;
    }
};

// @lc code=end
