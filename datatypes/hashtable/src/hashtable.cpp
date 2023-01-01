#include <hashtable.hpp>
#include <iostream>

Hashtable::Hashtable(std::function<size_t(const std::string&)> new_hash_function) {

    hash_function = new_hash_function;
    
    num_elements = 0;
    num_buckets = 1;
    
    buckets = std::vector<List>(32);

}

void Hashtable::insert(const std::string x) {

    bool load_factor_valid = double(num_elements) / double(num_buckets) < 0.75;
    
    if (!load_factor_valid) {
        rearrange_elements(2);
    }

    buckets[hash_function(x) % num_buckets].insert_front(x);
    num_elements++;

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

    num_elements --;

    bool load_factor_valid = double(num_elements) / double(num_buckets) > 0.25;
    
    if (!load_factor_valid) {
        rearrange_elements(0.5);
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

void Hashtable::rearrange_elements(double factor) {
    
    List tmp = List();

    // remove all elements and store in tmp
    for (int i = 0; i < num_buckets; i++) {
        while (buckets[i].get_head()) {
            tmp.insert_front(buckets[i].get_head()->get_data());
            buckets[i].remove_front();
            num_elements --;
        }
    }
    
    num_buckets = factor*num_buckets;

    // throw elements back into hashmap
    while (tmp.get_head()) {
        std::string x = tmp.get_head()->get_data();
        
        tmp.remove_front();

        insert(x);
    }

}

void Hashtable::print_hashtable() {

    for (int i = 0; i < num_buckets; i++) {
        std::cout << "Bucket " << i+1 << ":\t";
        buckets[i].print_linked_list();
    }

}

size_t Hashtable::get_num_elements() {

    return num_elements;

}

size_t Hashtable::get_num_buckets() {

    return num_buckets;

}
