#pragma once

#include <memory>

class List {



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
