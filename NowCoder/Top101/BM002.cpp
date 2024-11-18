

#include "NowCoderTop101.hpp"

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write code here
        if (m == n || head == nullptr) {
            return head;
        }
        auto p = head;
        int limit = m;
        if (m == 1) {
            for (; p->next != nullptr && limit < n; limit++) {
                auto q = p->next;
                p->next = q->next;
                q->next = head;
                head = q;
            }
        }
        if (m >= 2) {
            for (int i = 1; i < m - 1; ++i) {
                p = p->next;
            }
            ListNode *flag = p;
            p = p->next;
            ListNode *start = p;
            for (; p->next != nullptr && limit < n; ++limit) {
                auto q = p->next;
                p->next = q->next;
                q->next = start;
                start = q;
            }
            flag->next = start;
        }

        return head;
    }
};