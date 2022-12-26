#include <vector>
#include <iostream>
#include <cstddef>

class DirectedGraph {

    public:
        // declare constructor
        DirectedGraph(size_t num_nodes);
        // declare member functions
        void add_edge(size_t from_node, size_t to_node);
        void delete_edge(size_t from_node, size_t to_node);

        void print_graph();
    
    private:
        // declare attributes
        std::vector<std::vector<bool>> edges;

};
