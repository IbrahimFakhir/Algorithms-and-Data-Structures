#pragma once

#include <edge.hpp>
#include <node.hpp>

#include <cstddef>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

class NodeHash {

    public:
        size_t operator() (const Node& n) const;

};
typedef std::unordered_set<Node, NodeHash> NodeSet;

class EdgeHash {

    public:
        size_t operator() (const Edge& e) const;

};
typedef std::unordered_set<Edge, EdgeHash> EdgeSet;

class DirectedGraph {

    public:
        DirectedGraph();

        void insert_node(const Node& n);
        void insert_node(const index_t& idx);

        void delete_node(const Node& n);
        void delete_node(const index_t& idx);

        bool exists_node(const Node& n) const;
        bool exists_node(const index_t& idc) const;

        const NodeSet& get_node_set() const;

        // add existing edge
        void insert_edge(const Edge& e);
        // create and add edge
        void insert_edge(const index_t& start, const index_t& end);

        void delete_edge(const Edge& e);
        void delete_edge(const index_t& start, const index_t& end);

        bool exists_edge(const Edge& e) const;
        bool exists_edge(const index_t& start, const index_t& end) const;

    private:
        NodeSet node_set;
        EdgeSet edge_set;

};
