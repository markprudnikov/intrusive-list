#ifndef INTRUSIVE_LIST_POINT_LIST_HPP
#define INTRUSIVE_LIST_POINT_LIST_HPP

#include <iostream>
#include "intrusive_list.hpp"

struct PointNode : IntrusiveNode {
    int x, y;

    PointNode(int x, int y) : IntrusiveNode(), x(x), y(y) {}
};

class PointList : public IntrusiveList {
public:

    void add_point(int x, int y) {
        auto *point = new PointNode(x, y);
        add_node(point);
    }

    void remove_point(int x, int y) {
        IntrusiveNode *node = head->next;
        while (node != head) {
            auto *point = (PointNode *) node;
            node = node->next;
            if (point->x == x && point->y == y) {
                remove_node(point);
                delete point;
            }
        }
    }

    void show_all_points() {
        IntrusiveNode *node = head->next;

        while (node != head) {
            auto *point = (PointNode *) node;
            node = node->next;
            std::cout << '(' << point->x << ", " << point->y << ") ";
        }
        std::cout << "\n";
    }

    void remove_all_points() {
        IntrusiveNode* node = head->next;

        while (node != head) {
            IntrusiveNode* next = node->next;
            delete node;
            node = next;
        }

        head->next = head;
        head->prev = head;
    }

    ~PointList() = default;
};

#endif //INTRUSIVE_LIST_POINT_LIST_HPP