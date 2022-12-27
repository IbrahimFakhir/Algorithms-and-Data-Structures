#pragma once

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

        ListNodeptr next(const ListNodeptr& node);

        ListNodeptr get_head();

        void print_list();
        
    private:
        // declare attributes
        ListNodeptr head;

};


class ListNode {

    public:
        // declare constructor
        ListNode(int data);

        // declare member functions
        int get_data();
        void set_data(int new_data);

        std::shared_ptr<ListNode> get_next();
        void set_next(const std::shared_ptr<ListNode>& new_next);

    private:
        // declare attributes
        int data;
        std::shared_ptr<ListNode> next;

};

typedef std::shared_ptr<ListNode> ListNodeptr;
