#include <hashtable.hpp>
#include <iostream>

Hashtable::Hashtable() :
    hash_function(std::hash<std::string>()) {

    num_buckets = 32;
    buckets = std::vector<List>(32);

}

void Hashtable::insert(const std::string x) {

    buckets[hash_function(x) % num_buckets].insert_front(x);

}

void Hashtable::remove(const std::string& x) {

    size_t index = hash_function(x) % num_buckets;

    ListNodeptr curr = buckets[index].get_head();
    
    if (curr && x == curr->get_data()) {
        buckets[index].remove_front();
        return;
    }
    
    while (curr->get_next()) {
        curr = curr->get_next();
        if (x == curr->get_data()) {
            buckets[index].remove_front();
            return;
        }
    }

}

bool Hashtable::is_in_table(const std::string& x) {

    size_t index = hash_function(x) % num_buckets;

    ListNodeptr curr = buckets[index].get_head();

    while (curr) {
        if (x == curr->get_data()) {
            return true;
        }
        curr = curr->get_next();
    }

    return false;

}

void Hashtable::print_hashtable() {

    for (int i = 0; i < num_buckets; i++) {
        std::cout << "Bucket " << i+1 << ":\t";
        buckets[i].print_linked_list();
    }

}

size_t Hashtable::get_size() {

    return num_buckets;

}
