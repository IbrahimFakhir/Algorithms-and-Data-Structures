#pragma once

#include <node.hpp>
#include <cstddef>
#include <string>

class Edge {

    public:
        Edge(const Node& start_node, const Node& end_node);

        const Node& get_start_node() const;
        const Node& get_end_node() const;

        bool operator== (const Edge& other) const;

        std::string get_string() const;

    private:
        const Node start;
        const Node end;

};
