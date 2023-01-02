#pragma once

#include <linked_list_str.hpp>
#include <memory>
#include <string>
#include <vector>
#include <cstddef>
#include <functional>

class Hashtable {

    public:
        Hashtable(std::function<size_t(const std::string&)> hash_function);

        void insert(const std::string x);
        void remove(const std::string& x);

        bool is_in_table(const std::string& x);

        void print_hashtable();

        size_t get_num_elements();
        size_t get_num_buckets();

    private:
        std::function<size_t(const std::string&)> hash_function;

        size_t num_elements;
        size_t num_buckets;

        std::vector<List> buckets;
        /* 
        * helper function for insert and remove functions
        *
        * @param factor the factor by which the number of buckets will be multiplied during rearrangement 
        */
        void rearrange_elements(double factor);

};
