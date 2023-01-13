#include <directed_graph.hpp>

size_t NodeHash::operator() (const Node& k) const {
    
    return k.get_index_t();

}

size_t EdgeHash::operator() (const Edge& k) const {

    return k.get_start_node().get_index_t() ^ k.get_end_node().get_index_t();

}
