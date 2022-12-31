#pragma once

#include <memory>
#include <string>

class ListNode {

    public:
        // declare constructor
        ListNode(std::string data);

        // declare member functions
        std::string get_data();
        void set_data(std::string new_data);

        std::shared_ptr<ListNode> get_next();
        void set_next(const std::shared_ptr<ListNode>& new_next);

    private:
        // declare attributes
        std::string data;
        std::shared_ptr<ListNode> next;

};

typedef std::shared_ptr<ListNode> ListNodeptr;
