#include <doubly_linked_list.hpp>

#include <iostream>

int main() {

    DoublyLinkedList l = DoublyLinkedList();

    l.insert_front(5);
    l.insert_after(l.get_first(), 3);
    l.insert_after(l.get_first()->get_next(), 7);

    l.print_doubly_linked_list();

    l.remove(l.get_first()->get_next());
    
    l.print_doubly_linked_list();

}
