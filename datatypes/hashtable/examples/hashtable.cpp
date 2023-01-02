#include <hashtable.hpp>

#include <iostream>

int main() {

    Hashtable h = Hashtable(std::hash<std::string>());

    h.insert("d");
    h.insert("e");
    h.insert("g");

    h.remove("g");

    h.print_hashtable();

}
