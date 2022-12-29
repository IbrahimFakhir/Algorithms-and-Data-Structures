#pragma once

#include <doubly_linked_listnode.hpp>
#include <memory>
#include <iostream>

class DoublyLinkedList {
    public:
        DoublyLinkedList();

        DLinkedListNodeptr get_first();
        DLinkedListNodeptr get_last();

        void insert_front(int x);
        void insert_after(const DLinkedListNodeptr& node, int x);
        
        void remove(const DLinkedListNodeptr& node);

        DLinkedListNodeptr get_next(const DLinkedListNodeptr& node);
        WeakDLinkedListNodeptr get_prev(const DLinkedListNodeptr& node);

    private:
        DLinkedListNodeptr head;
        DLinkedListNodeptr tail;

};
