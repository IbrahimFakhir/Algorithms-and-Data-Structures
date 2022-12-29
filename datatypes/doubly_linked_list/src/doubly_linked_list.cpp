#include <doubly_linked_list.hpp>
#include <doubly_linked_listnode.hpp>

DoublyLinkedList::DoublyLinkedList() {

    head = nullptr;
    tail = nullptr;

}

DLinkedListNodeptr DoublyLinkedList::get_first() {

    return head;

}
DLinkedListNodeptr DoublyLinkedList::get_last() {

    return tail;

}



DoublyLinkedListNode::DoublyLinkedListNode(int new_data) {

    data = new_data;

    next = nullptr;
    // initialize prev??

}

DLinkedListNodeptr DoublyLinkedListNode::get_next() {
    
    return next;

}
void DoublyLinkedListNode::set_next(const std::shared_ptr<DoublyLinkedListNode>& new_next) {

    next = new_next;

}

WeakDLinkedListNodeptr DoublyLinkedListNode::get_prev() {

    return prev;

}
void DoublyLinkedListNode::set_prev(const std::weak_ptr<DoublyLinkedListNode>& new_prev) {

    prev = new_prev;

}

int DoublyLinkedListNode::get_data() {

    return data;

}
void DoublyLinkedListNode::set_data(int new_data) {

    data = new_data;

}
