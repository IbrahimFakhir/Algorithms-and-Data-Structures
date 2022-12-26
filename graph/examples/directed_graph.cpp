#include <directed_graph.hpp>

#include <iostream>

int main() {

    DirectedGraph h(4);

    h.add_edge(0, 2);
    h.add_edge(2, 3);
    h.add_edge(1, 0);

    h.delete_edge(2, 3);

    h.print_graph();

}
