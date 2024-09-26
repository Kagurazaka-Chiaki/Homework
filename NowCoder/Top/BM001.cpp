/**
 *
**/


#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x)
        : val(x), next(nullptr) {}
};

// auto slice(vector<int> const &v, int const &a, int const &b) {
//     auto it_a = v.begin(), it_b = v.begin();
//     advance(it_a, a);
//     advance(it_b, b);
//     vector<int> result;
//     for (auto &it = it_a; it != it_b; ++it) {
//         result.push_back(*it);
//     }
//     return result;
// }

void print_link_list(ListNode *l) {
    ListNode *pointer = l;
    while (pointer != nullptr) {
        printf("%p -> [%d, %p]\n", pointer, pointer->val, pointer->next);
        pointer = pointer->next;
    }
    cout << endl;
}

auto link_list(vector<int> const &input) -> ListNode * {
    ListNode *head = new ListNode(input[0]);
    ListNode *pointer = head;
    for (auto it = input.begin() + 1; it != input.end(); ++it) {
        ListNode *temp = new ListNode(*it);
        pointer->next = temp;
        pointer = pointer->next;
    }
    return head;
}

auto func(ListNode *head) -> ListNode * {
    if (head == nullptr) { return nullptr; }
    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr != nullptr) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */

    vector<int> input = {
            2, 1, 5, 3, 4
    };
    vector<int> output = {
            4, 3, 5, 1, 2
    };

    ListNode *a = link_list(input);
    print_link_list(a);
    ListNode *b = func(a);
    print_link_list(b);

    assert(true);

    return 0;
}