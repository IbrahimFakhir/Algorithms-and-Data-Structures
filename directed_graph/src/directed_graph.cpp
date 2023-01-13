#include <directed_graph.hpp>

size_t NodeHash::operator() (const Node& n) const {
    
    return n.get_index_t();

}

size_t EdgeHash::operator() (const Edge& e) const {

    return e.get_start_node().get_index_t() ^ e.get_end_node().get_index_t();

}

DirectedGraph::DirectedGraph() {}

void DirectedGraph::insert_node(const Node& n) {

    node_set.emplace(n);

}
void DirectedGraph::insert_node(const index_t& idx) {

    insert_node(Node(idx));

}
