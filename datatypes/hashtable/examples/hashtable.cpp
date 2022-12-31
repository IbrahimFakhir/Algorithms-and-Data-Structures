#include <hashtable.hpp>

#include <iostream>

int main() {

    Hashtable h = Hashtable();
    std::cout << "Size: " << h.get_size() << std::endl;

    std::vector<std::string> buchstaben = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    for (std::string buchstabe : buchstaben) {
        h.insert(buchstabe);
    }

    h.insert("Eren");
    h.insert("Eren");

    h.remove("Eren");

    h.print_hashtable();
    
    std::cout << h.is_in_table("Eren") << std::endl;
    std::cout << h.is_in_table("Ibo") << std::endl;

}
