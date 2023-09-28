/**
 *
**/

#include "LinkedList.hpp"
#include "Node.hpp"

#include <algorithm>
#include <iostream>
#include <memory>

auto reverse_list(lib::ListNode *head) {
    auto p = head;
    while (p->next != nullptr) {
        auto q = p->next;
        p->next = q->next;
        q->next = head;
        head = q;
    }
    return head;
}

auto main(int argc, char const *argv[]) -> int {
    (void) argc;
    (void) argv;
    /* code */
    std::cout << "Hello, 世界! \xF0\x9F\x98\x89 \n"
              << std::endl;

    auto l = lib::LinkedList({1, 2, 3});

    l.logger();

    l.head = reverse_list(l.head);

    l.logger();

    return 0;
}
