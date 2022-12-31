#pragma once

#include <linked_list_str.hpp>
#include <memory>
#include <string>
#include <vector>
#include <cstddef>
#include <functional>

class Hashtable {

    public:
        Hashtable();

        void insert(std::string x);
        void remove(std::string& x);

        bool is_in_table(const std::string& x);

        void print_hashtable();

        size_t get_size();

    private:
        const std::function<size_t(const std::string&)> hash_function;

        std::vector<List> buckets;

        size_t num_buckets;

};
