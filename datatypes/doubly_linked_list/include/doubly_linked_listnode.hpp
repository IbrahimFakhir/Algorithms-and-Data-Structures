#pragma once

#include <memory>

class DoublyLinkedListNode {

    public:
        DoublyLinkedListNode(int new_data);

        std::shared_ptr<DoublyLinkedListNode> get_next();
        void set_next(const std::shared_ptr<DoublyLinkedListNode>& new_next);

        std::weak_ptr<DoublyLinkedListNode> get_prev();
        void set_prev(const std::weak_ptr<DoublyLinkedListNode>& new_prev);

        int get_data();
        void set_data(int new_data);

    private:
        std::shared_ptr<DoublyLinkedListNode> next;
        std::weak_ptr<DoublyLinkedListNode> prev;

        int data;

};

typedef std::shared_ptr<DoublyLinkedListNode> DLinkedListNodeptr;
typedef std::weak_ptr<DoublyLinkedListNode> WeakDLinkedListNodeptr;
