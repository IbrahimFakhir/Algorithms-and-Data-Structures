#include <directed_graph.hpp>

DirectedGraph::DirectedGraph(size_t num_nodes) {
    
    std::vector<bool> bool_array(num_nodes, false);
    edges = std::vector<std::vector<bool>>(num_nodes, bool_array);

}

void DirectedGraph::add_edge(size_t from_node, size_t to_node) {

    if (from_node < edges.size() && to_node < edges.size()) {
        edges[from_node][to_node] = true;
    }

}
void DirectedGraph::delete_edge(size_t from_node, size_t to_node) {

    if (from_node < edges.size() && to_node < edges.size()) {
        edges[from_node][to_node] = false;
    }

}

void DirectedGraph::print_graph() {
    std::cout << "nodes and edges:" << std::endl;
    for (int i = 0; i < edges.size(); i++) {
        std::cout << "node " << i << ": ";
        for (int j = 0; j < edges.size(); j++) {
            if (edges[i][j] == true) {
                std::cout << j << " ";
            }
        }
        std::cout << std::endl;
    }

}
