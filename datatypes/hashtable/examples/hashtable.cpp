#include <hashtable.hpp>

#include <iostream>

int main() {

    Hashtable h = Hashtable();
    std::cout << "Size: " << h.get_size() << std::endl;

    h.print_hashtable();
    
}
