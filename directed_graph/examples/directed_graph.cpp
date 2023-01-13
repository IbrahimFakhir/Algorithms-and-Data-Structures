#include <iostream>

#include <directed_graph.hpp>

int main() {

    DirectedGraph g = DirectedGraph();

    std::cout << g.exists_edge(1, 2) << std::endl;

    g.insert_edge(1, 2);
    g.insert_edge(2, 1);

    std::cout << g.exists_edge(1, 2) << std::endl;

    g.print_graph();

    for (const auto& e : g.get_incoming_edges(2)) {
        std::cout << e.get_string();
    }

}
