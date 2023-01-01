#include <hashtable.hpp>

#include <iostream>

int main() {

    Hashtable h = Hashtable(std::hash<std::string>());

    h.insert("d");
    h.insert("e");
    h.insert("g");
    h.insert("dasg");
    h.insert("g");
    h.insert("g");
    h.insert("g");
    h.insert("g");
    h.insert("g");
    h.insert("g");
    h.insert("g");
    h.insert("g");


    h.print_hashtable();
    std::cout << "Size: " << h.get_num_buckets() << std::endl;

}
