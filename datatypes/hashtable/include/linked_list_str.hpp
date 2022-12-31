#pragma once

#include <list_node_str.hpp>
#include <string>
#include <memory>

class List {

    public:
        // declare constructor
        List();

        // declare member functions
        void insert_front(std::string x);
        void insert_after(const ListNodeptr& node, std::string x);

        void remove_front();
        void remove_after(const ListNodeptr& node);
        
        ListNodeptr next(const ListNodeptr& node);

        ListNodeptr get_head();

        size_t get_size();

        void print_linked_list();
        
    private:
        // declare attributes
        ListNodeptr head;
        size_t size;

};
