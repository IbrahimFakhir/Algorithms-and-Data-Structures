#include <linked_list.hpp>

ListNode::ListNode(int new_data) {

    data = new_data;
    next = nullptr;
    
}

int ListNode::get_data() {

    return data;

}
void ListNode::set_data(int new_data) {

    data = new_data;
    
}

ListNodeptr ListNode::get_next() {

    return next;

}
void ListNode::set_next(const std::shared_ptr<ListNode>& new_next) {

    next = new_next;

}
