#include <linked_list.hpp>
#include <list_node.hpp>

#include <iostream>

List::List() {

    head = nullptr;

}

void List::insert_front(int x) {

    ListNodeptr new_ptr;
    new_ptr = std::make_shared<ListNode>(x);

    new_ptr->set_next(head);

    head = new_ptr;

}
void List::insert_after(const ListNodeptr& node, int x) {

    ListNodeptr new_ptr;
    new_ptr = std::make_shared<ListNode>(x);

    new_ptr->set_next(node->get_next());

    node->set_next(new_ptr);

}

void List::remove_front() {

    head = head->get_next();

}
void List::remove_after(const ListNodeptr& node) {

    node->set_next(next(next(node)));

}

ListNodeptr List::next(const ListNodeptr& node) {

    return node->get_next();

}

ListNodeptr List::get_head() {

    return head;

}

void List::print_linked_list() {

    ListNodeptr curr = head;

    std::cout << "HEAD -> ";

    while (curr) {
        std::cout << curr->get_data() << " -> ";
        curr = curr->get_next();
    }

    std::cout << "NULL" << std::endl;

}



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
