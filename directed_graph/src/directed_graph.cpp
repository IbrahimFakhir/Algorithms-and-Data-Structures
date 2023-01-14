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

void DirectedGraph::delete_node(const Node& n) {

    // erase node itself first
    node_set.erase(n);

    // delete all outgoing (from deleted node) edges
    for (const auto& e : outgoing_edges[n]) {
        incoming_edges[e.get_end_node()].erase(e);
        edge_set.erase(e);
    }

    // delete all incoming (to deleted node) edges
    for (const auto& e : incoming_edges[n]) {
        outgoing_edges[e.get_start_node()].erase(e);
        edge_set.erase(e);
    }

}
void DirectedGraph::delete_node(const index_t& idx) {

    delete_node(Node(idx));

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

    return get_incoming_edges(Node(idx));

}


void DirectedGraph::print_graph() const {

    std::cout << "Nodes:\n\t";
    for (const auto& n : node_set) {
        std::cout << n.get_string() << " ";
    }
    std::cout << std::endl;

    std::cout << "Edges:\n\t";
    for (const auto& e : edge_set) {
        std::cout << e.get_string() << " ";
    }

    std::cout << std::endl;

}
std::vector<Node> DirectedGraph::breath_first_search(const Node& start) const {

    // result in right order
    std::vector<Node> result;
    // already visited
    std::unordered_set<Node, NodeHash> marked;
    // to visit
    std::queue<Node> queue;

    queue.push(start);
    while (!queue.empty()) {
        Node& curr = queue.front();
        queue.pop();

        

        if (marked.find(curr) == marked.end()) {
            marked.insert(curr);
            result.push_back(curr);
            for (const auto& e : get_outgoing_edges(curr)) {
                if (marked.find(e.get_end_node()) == marked.end()) {
                    queue.push(e.get_end_node());
                }
            }
        }
    }

    return result;

}
std::vector<Node> DirectedGraph::breath_first_search(const index_t& idx) const {

    return breath_first_search(Node(idx));

}

std::vector<Node> DirectedGraph::depth_first_search(const Node& start) const {

    // result in right order
    std::vector<Node> result;
    // already visited
    std::unordered_set<Node, NodeHash> marked;
    // to visit
    std::stack<Node> stack;

    stack.push(start);
    while (!stack.empty()) {
        Node& curr = stack.top();
        stack.pop();

        if (marked.find(curr) == marked.end()) {
            marked.insert(curr);
            result.push_back(curr);
            for (const auto& e : get_outgoing_edges(curr)) {
                if (marked.find(e.get_end_node()) == marked.end()) {
                    stack.push(e.get_end_node());
                }
            }
        }
    }

    return result;

}
std::vector<Node> DirectedGraph::depth_first_search(const index_t& idx) const {

    return depth_first_search(Node(idx));

}
