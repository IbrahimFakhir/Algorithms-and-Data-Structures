#include <hashtable.hpp>

#include <iostream>

int main() {

    Hashtable h = Hashtable(std::hash<std::string>());

    h.insert("d");
    h.insert("e");
    h.insert("g");

    h.remove("g");
    
    std::cout << "is letter e in table? " << h.is_in_table("e") << std::endl;
    std::cout << "is letter g in table? " << h.is_in_table("g") << std::endl;

    h.print_hashtable();

}
