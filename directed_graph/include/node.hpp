#pragma once

#include <cstddef>
#include <string>

typedef size_t index_t;

class Node {

    public:
        Node(const index_t node_index);

        bool operator== (const Node& other) const;
        
        index_t get_index_t() const;

        std::string get_string() const;

    private:
        const index_t idx;

};
