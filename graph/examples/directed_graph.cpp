#include <directed_graph.hpp>

#include <iostream>

void print_int_array(const std::vector<int>& array) {

    for (const int& num : array) {
        std::cout << num;
        std::cout << " ";
    }
    std::cout << std::endl;

}

int main() {

    DirectedGraph g(10);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 4);
    g.add_edge(1, 3);   
    g.add_edge(3, 5);
    g.add_edge(5, 6);
    g.add_edge(5, 7);
    g.add_edge(5, 8);
    g.add_edge(8, 9);

    g.print_graph();

    std::vector<int> result = g.breath_first_search(0);
    std::cout << std::endl << "result bfs:" << std::endl;
    print_int_array(result);

    result = g.depth_first_search(0);
    std::cout << std::endl << "result dfs:" << std::endl;
    print_int_array(result);

}
