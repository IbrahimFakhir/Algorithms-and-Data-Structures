#include <simple_directed_graph.hpp>
#include <queue>
#include <stack>

// define constructor
DirectedGraph::DirectedGraph(size_t num_nodes) {
    
    std::vector<bool> bool_array(num_nodes, false);
    edges = std::vector<std::vector<bool>>(num_nodes, bool_array);

}
// define member functions
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

std::vector<int> DirectedGraph::breath_first_search(int s) {

    std::queue<int> queue;
    std::vector<bool> visited(edges.size(), false);
    std::vector<int> result;

    queue.push(s);

    while (!queue.empty()) {
        int v = queue.front();
        queue.pop();
        for (int w = 1; w < edges.size(); w++) {
            if (edges[v][w] && !visited[w]) {
                queue.push(w);
                visited[w] = true;
            }
        }
        result.push_back(v);
    }

    return result;

}
std::vector<int> DirectedGraph::depth_first_search(int s) {

    std::stack<int> stack;
    std::vector<bool> visited(edges.size(), false);
    std::vector<int> result;

    stack.push(s);

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();
        for (int w = 1; w < edges.size(); w++) {
            if (edges[v][w] && !visited[w]) {
                stack.push(w);
                visited[w] = true;
            }
        }
        result.push_back(v);
    }

    return result;

}

void DirectedGraph::print_graph() {
    std::cout << std::endl;
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
