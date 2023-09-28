

#ifndef NODE
#define NODE

#include <iostream>
#include <memory>

namespace lib {

    struct ListNode {
            int val;
            ListNode *next;

            ListNode()
                : val(0), next(nullptr) {}

            ListNode(int x)
                : val(x), next(nullptr) {}

            ListNode(int x, ListNode *next)
                : val(x), next(next) {}

            friend auto operator<<(std::ostream &os, ListNode const &n) -> std::ostream & {
                return os << &n << ": [" << n.val << "] -> [" << n.next << "]"; // << "[" << n.prev << "] <- " << &n
            }
    };

    // template<typename T>
    // struct ListNode {
    //         T value;

    //         ListNode *next = nullptr;

    //         ListNode(T value)
    //             : value(value), next(nullptr){};

    //         ListNode(ListNode const &other) = delete;
    //         auto operator=(ListNode const &other) -> ListNode & = delete;

    //         ListNode(ListNode &&other) noexcept = delete;
    //         auto operator=(ListNode &&other) noexcept -> ListNode & = delete;

    //         ~ListNode() noexcept = default;

    //         explicit operator std::string() const {
    //             auto result = std::string();
    //             return result;
    //         }

    //         friend auto operator<<(std::ostream &os, ListNode const &n) -> std::ostream & {
    //             return os << &n << ": [" << n.value << "] -> [" << n.next << "]"; // << "[" << n.prev << "] <- " << &n
    //         }
    // };

    template<typename T>
    struct Node {

            T value;

            Node *prev = nullptr;

            std::unique_ptr<Node> next = nullptr;

            Node(T value)
                : value(value), prev(nullptr), next(nullptr){};

            Node(Node const &other) = delete;
            auto operator=(Node const &other) -> Node & = delete;

            Node(Node &&other) noexcept = delete;
            auto operator=(Node &&other) noexcept -> Node & = delete;

            ~Node() noexcept = default;

            explicit operator std::string() const {
                auto result = std::string();
                return result;
            }

            friend auto operator<<(std::ostream &os, Node const &n) -> std::ostream & {
                return os << "[" << n.prev << "] <- " << &n
                          << ": [" << n.value << "] -> [" << n.next << "]";
            }
    };

} // namespace lib


#endif // NODE
