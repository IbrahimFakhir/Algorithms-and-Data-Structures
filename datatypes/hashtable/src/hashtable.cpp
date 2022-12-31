#include <hashtable.hpp>

Hashtable::Hashtable() :
    hash_function(std::hash<std::string>()) {

    num_buckets = 32;
    buckets = std::vector<List>(32);

}

void Hashtable::insert(std::string x) {



}

size_t Hashtable::get_size() {

    return num_buckets;

}
