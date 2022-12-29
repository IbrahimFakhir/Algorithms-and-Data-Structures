#pragma once

#include <doubly_linked_listnode.hpp>
#include <memory>
#include <iostream>

class DoublyLinkedList {
    public:
        DoublyLinkedList();

        DLinkedListNodeptr get_first();
        DLinkedListNodeptr get_last();

    private:
        DLinkedListNodeptr head;
        DLinkedListNodeptr tail;

};
