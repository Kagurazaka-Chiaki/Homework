


#ifndef LINKEDLIST
#define LINKEDLIST

#include "Node.hpp"
#include <initializer_list>

#include <algorithm>
#include <memory>
#include <string>

namespace lib {

    // Raw Pointer
    struct LinkedList {

            ListNode *head = nullptr;

            ListNode *tail = nullptr;

            LinkedList() = default;

            LinkedList(std::initializer_list<int> init_list) {
                for (auto &i: init_list) {
                    auto node = new ListNode(i);
                    if (head == nullptr && tail == nullptr) {
                        head = node;
                        tail = node;
                    } else {
                        tail->next = node;
                        tail = tail->next;
                    }
                }
            }

            ~LinkedList() noexcept {
                auto p = head;
                while (p != nullptr) {
                    auto flag = p;
                    p = p->next;
                    delete flag;
                }
            }

            auto logger() const -> void {
                auto p = head;
                std::cout << "list: { \n"
                          << head << '\n'
                          << tail << '\n';
                while (p != nullptr) {
                    std::cout << ' ' << ' ' << *p << '\n';
                    p = p->next;
                }
                std::cout << '}' << std::endl;
            }

            explicit operator std::vector<int>() const {
                auto vec = std::vector<int>();
                for (auto p = head; p != nullptr; p = p->next) {
                    vec.push_back(p->val);
                }
                return vec;
            }
    };

    // Unique Pointer
    template<typename T>
    struct List {

            std::unique_ptr<Node<T>> head;

            Node<T> *tail = nullptr;

            List() = default;

            List<T>(std::initializer_list<T> init_list) {
                for (auto &item: init_list) {
                    auto node = std::make_unique<Node<T>>(item);
                    push_back(node);
                }
            }

            // copy constructor
            List<T>(const List<T> &other) = delete;

            // move constructor
            List<T>(List<T> &&other) noexcept = delete;

            // copy assignment
            auto operator=(const List<T> &other) -> List<T> & = delete;

            // move assignment
            auto operator=(List<T> &&other) noexcept -> List<T> & = delete;

            ~List() = default;

            auto log() const -> void {
                auto p = head.get();
                std::cout << "list: { \n"
                          << head << '\n'
                          << tail << '\n';
                while (p != nullptr) {
                    std::cout << ' ' << ' ' << *p << '\n';
                    p = p->next.get();
                }
                std::cout << '}' << std::endl;
            }

            auto push_back(std::unique_ptr<Node<T>> &item) -> void {
                if (head == nullptr and tail == nullptr) {
                    head = std::move(item);
                    tail = head.get();
                } else {
                    item->prev = tail;
                    tail->next = std::move(item);
                    tail = tail->next.get();
                }
            }

            auto push_front(std::unique_ptr<Node<T>> &item) -> void {
                if (head == nullptr and tail == nullptr) {
                    head = std::move(item);
                    tail = head.get();
                } else {
                    item->next = std::move(head);
                    item->next->prev = item.get();
                    head = std::move(item);
                }
            }

            auto pop_back() -> std::unique_ptr<Node<T>> {
                if (tail == nullptr) {
                    return nullptr;
                }
                if (tail->prev == nullptr) {
                    return pop_front();
                }
                tail = tail->prev;
                auto flag = std::move(tail->next);
                flag->prev = nullptr;
                return flag;
            }

            auto pop_front() -> std::unique_ptr<Node<T>> {
                if (head == nullptr) {
                    return nullptr;
                }
                auto flag = std::move(head);
                if (flag->next != nullptr) {
                    head = std::move(flag->next);
                    head->prev = nullptr;
                } else {
                    head = nullptr;
                    tail = nullptr;
                }
                flag->next = nullptr;
                flag->prev = nullptr;
                return flag;
            }

            auto remove(Node<T> *item) -> std::unique_ptr<Node<T>> {
                if (item == nullptr) {
                    return nullptr;
                }
                if (item->prev == nullptr) {
                    return pop_front();
                }
                if (item->next == nullptr) {
                    return pop_back();
                }

                auto flag = item->prev;
                auto result = std::move(flag->next);
                flag->next = std::move(item->next);
                flag->next->prev = flag;

                item->next = nullptr;
                item->prev = nullptr;

                return result;
            }

            auto reverse() {
                tail = head.get();
                auto pointer = head.release();
                auto p = pointer;
                while (p->next != nullptr) {
                    // p->next->prev = nullptr;
                    // p->prev = p->next.get();
                    auto q = p->next.release();
                    p->next.reset(q->next.release());
                    q->next.reset(pointer);
                    pointer = q;
                    pointer->next->prev = pointer;
                }
                pointer->prev = nullptr;
                head.reset(pointer);
            }
    };

} // namespace lib

#endif // LINKEDLIST