#ifndef INTRUSIVE_LIST_INTRUSIVE_LIST_HPP
#define INTRUSIVE_LIST_INTRUSIVE_LIST_HPP

#include <cstdlib>

struct IntrusiveNode {
    IntrusiveNode* next = nullptr;
    IntrusiveNode* prev = nullptr;
};

class IntrusiveList {
public:
    IntrusiveNode* head;

    IntrusiveList() {
        head = new IntrusiveNode();
        head->next = head;
        head->prev = head;
    }

    void add_node(IntrusiveNode* node) const {
        IntrusiveNode* last = head->prev;

        node->prev = last;
        node->next = head;

        head->prev = node;
        last->next = node;
    }

    void remove_node(IntrusiveNode* node) const {
        if (node != head) {
            IntrusiveNode* prev = node->prev;
            IntrusiveNode* next = node->next;

            prev->next = next;
            next->prev = prev;
        }
    }

    [[nodiscard]] std::size_t size() const {
        std::size_t sz = 0;

        IntrusiveNode* node = head->next;

        for (; node != head; node = node->next) {
            ++sz;
        }

        return sz;
    }

    ~IntrusiveList() {
        IntrusiveNode* node = head->next;

        while (node != head) {
            IntrusiveNode* next = node->next;
            delete node;
            node = next;
        }

        delete head;
    }
};

#endif //INTRUSIVE_LIST_INTRUSIVE_LIST_HPP