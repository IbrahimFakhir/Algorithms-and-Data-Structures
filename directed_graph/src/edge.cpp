#include <edge.hpp>

Edge::Edge(const Node& start_node, const Node& end_node) : 
    start(start_node), end(end_node) {}

const Node& Edge::get_start_node() const {
    
    return start;

}
const Node& Edge::get_end_node() const {

    return end;

}

bool Edge::operator==(const Edge& other) const {

    return start == other.get_start_node() and end == other.get_end_node();

}

std::string Edge::get_string() const {

    return "(" + start.get_string() + " -> " + end.get_string() + ")";

}
