#pragma once

#include <list_node.hpp>
#include <memory>

class List {

    public:
        // declare constructor
        List();

        // declare member functions
        void insert_front(int x);
        void insert_after(const ListNodeptr& node, int x);

        void remove_front();
        void remove_after(const ListNodeptr& node);
        // alternative to using next func: node->get_next()
        ListNodeptr next(const ListNodeptr& node);

        ListNodeptr get_head();

        void print_linked_list();
        
    private:
        // declare attributes
        ListNodeptr head;

};
