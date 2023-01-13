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

bool DirectedGraph::exists_node(const Node& n) const {

    return node_set.count(n) >= 1;

}
bool DirectedGraph::exists_node(const index_t& idx) const {

    return exists_node(Node(idx));

}

const NodeSet& DirectedGraph::get_node_set() const {

    return node_set;

}


void DirectedGraph::insert_edge(const Edge& e) {

    // prevent loops
    if (e.get_start_node() == e.get_end_node()) {
        return;
    }

    // insert connecting nodes if needed
    insert_node(e.get_start_node());
    insert_node(e.get_end_node());

    // insert the edge itself
    edge_set.emplace(e);
    outgoing_edges[e.get_start_node()].emplace(e);
    incoming_edges[e.get_end_node()].emplace(e);

}
void DirectedGraph::insert_edge(const index_t& start, const index_t& end) {

    insert_edge(Edge(start, end));

}

void DirectedGraph::delete_edge(const Edge& e) {

    edge_set.erase(e);

    outgoing_edges[e.get_start_node()].erase(e);
    incoming_edges[e.get_end_node()].erase(e);

}
void DirectedGraph::delete_edge(const index_t& start, const index_t& end) {

    delete_edge(Edge(start, end));

}

bool DirectedGraph::exists_edge(const Edge& e) const {

    return edge_set.count(e) >= 1;

}
bool DirectedGraph::exists_edge(const index_t& start, const index_t& end) const {

    return exists_edge(Edge(start, end));

}

EdgeSet DirectedGraph::get_outgoing_edges(const Node& n) const {

    if (outgoing_edges.count(n) >= 1) {
        return outgoing_edges.at(n);
    }
    // return empty set
    return EdgeSet();

}
EdgeSet DirectedGraph::get_outgoing_edges(const index_t& idx) const {

    return get_outgoing_edges(Node(idx));

}

EdgeSet DirectedGraph::get_incoming_edges(const Node& n) const {

    if (incoming_edges.count(n) >= 1) {
        return incoming_edges.at(n);
    }
    // return empty set
    return EdgeSet();

}
EdgeSet DirectedGraph::get_incoming_edges(const index_t& idx) const {

    get_incoming_edges(Node(idx));

}
