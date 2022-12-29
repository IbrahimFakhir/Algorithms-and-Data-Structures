#include <linked_list.hpp>

#include <iostream>

int main() {

    List l = List();

    l.insert_front(5);
    l.insert_front(3);
    l.insert_after(l.next(l.get_head()), 6);
    l.insert_front(-214);

    l.remove_front();
    l.remove_after(l.get_head());

    l.print_linked_list();

}
