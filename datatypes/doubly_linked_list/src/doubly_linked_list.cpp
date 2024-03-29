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

void DoublyLinkedList::insert_front(int x) {

    DLinkedListNodeptr new_node = std::make_shared<DoublyLinkedListNode>(x);

    if (head) {
        head->set_prev(new_node);
        new_node->set_next(head);
    }
    else {
        tail = new_node;
    }

    head = new_node;

}
void DoublyLinkedList::insert_after(const DLinkedListNodeptr& node, int x) {

    DLinkedListNodeptr new_node = std::make_shared<DoublyLinkedListNode>(x);

    // inserting after any node except the last one
    if (node->get_next()) {
        new_node->set_prev(node);
        new_node->set_next(node->get_next());
        node->get_next()->set_prev(new_node);
        node->set_next(new_node);
    }
    // inserting after the last node
    else {
        new_node->set_prev(node);
        node->set_next(new_node);
        tail = new_node;
    }

}

void DoublyLinkedList::remove(const DLinkedListNodeptr& node) {

    // case if node is only element in list
    if (head == node && tail == node) {
        head = nullptr;
        tail = nullptr;
    }
    // case if node is in between two elements in list
    if (node->get_next() && node->get_prev().lock()) {
        node->get_prev().lock()->set_next(node->get_next());
        node->get_next()->set_prev(node->get_prev().lock());
    }
    // case if node is the first element in list
    if (head == node && node->get_next()) {
        head = node->get_next();
        node->get_next()->set_prev(nullptr);
    }
    // case if node is the last element in list
    if (tail == node && node->get_prev().lock()) {
        node->set_next(nullptr);
        tail = node->get_prev().lock();
    }

}

DLinkedListNodeptr DoublyLinkedList::get_next(const DLinkedListNodeptr& node) {

    return node->get_next();

}
WeakDLinkedListNodeptr DoublyLinkedList::get_prev(const DLinkedListNodeptr& node) {

    return node->get_prev();

}

void DoublyLinkedList::print_doubly_linked_list() {

    DLinkedListNodeptr curr = head;

    std::cout << "Head -> ";

    while (curr->get_next()) {
        std::cout << curr->get_data() << " -> ";
        curr = curr->get_next();
    }
    std::cout << curr->get_data();
    std::cout << " <- Tail" << std::endl << std::endl;

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
void DoublyLinkedListNode::set_prev(const std::shared_ptr<DoublyLinkedListNode>& new_prev) {

    prev = new_prev;

}

int DoublyLinkedListNode::get_data() {

    return data;

}
void DoublyLinkedListNode::set_data(int new_data) {

    data = new_data;

}
