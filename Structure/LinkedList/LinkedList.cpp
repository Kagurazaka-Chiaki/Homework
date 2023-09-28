//


#include "LinkedList.hpp"

#include "Node.hpp"

auto reverse_list(lib::Node<int> *head) -> lib::Node<int> * {
    auto p = head;
    while (p->next != nullptr) {
        auto q = p->next.release();
        p->next.reset(q->next.release());
        q->next.reset(head);
        head = q;
        head->next->prev = head;
    }
    head->prev = nullptr;
    return head;
}

int main(int argc, char const *argv[]) {
    (void) argc;
    (void) argv;
    /* code */

    auto a = std::make_unique<lib::Node<int>>(1);
    auto b = std::make_unique<lib::Node<int>>(2);
    auto c = std::make_unique<lib::Node<int>>(3);

    auto l = lib::List<int>({1, 2, 3, 4, 5});

    l.log();

    l.tail = l.head.get();
    l.head.reset(reverse_list(l.head.release()));

    l.log();

    l.reverse();

    l.log();

    return 0;
}