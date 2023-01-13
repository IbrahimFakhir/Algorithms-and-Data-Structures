#include <node.hpp>

Node::Node(const index_t node_index) : idx(node_index) {}

bool Node::operator==(const Node& other) const {

    return idx == other.get_index_t();

}

index_t Node::get_index_t() const {

    return idx;

}

std::string Node::get_string() const {

    return std::to_string(idx);

}
