#include <iostream>

#include <directed_graph.hpp>

int main() {

    DirectedGraph g = DirectedGraph();

    g.insert_edge(1, 2);
    g.insert_edge(2, 3);
    g.insert_edge(2, 4);
    g.insert_edge(3, 2);
    g.insert_edge(4, 1);
    
    g.print_graph();
    std::cout << "Incoming Edges node 2:\n";
    for (const auto& e : g.get_incoming_edges(2)) {
        std::cout << e.get_string() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Outgoing Edges node 2:\n";
    for (const auto& e : g.get_outgoing_edges(2)) {
        std::cout << e.get_string() << std::endl;
    }

    std::cout << "\n\nDeleting (2 -> 4) and (3 -> 2)" << std::endl;
    g.delete_edge(2, 4);
    g.delete_edge(3, 2);

    g.print_graph();
    std::cout << "Incoming Edges node 2:\n";
    for (const auto& e : g.get_incoming_edges(2)) {
        std::cout << e.get_string() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Outgoing Edges node 2:\n";
    for (const auto& e : g.get_outgoing_edges(2)) {
        std::cout << e.get_string() << std::endl;
    }

}
