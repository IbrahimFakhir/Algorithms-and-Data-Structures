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

typedef std::unordered_map<Node, EdgeSet, NodeHash> OutgoingEdges;
typedef std::unordered_map<Node, EdgeSet, NodeHash> IncomingEdges;

class DirectedGraph {

    public:
        DirectedGraph();

        void insert_node(const Node& n);
        void insert_node(const index_t& idx);

        void delete_node(const Node& n);
        void delete_node(const index_t& idx);

        bool exists_node(const Node& n) const;
        bool exists_node(const index_t& idx) const;

        const NodeSet& get_node_set() const;


        void insert_edge(const Edge& e);
        void insert_edge(const index_t& start, const index_t& end);

        void delete_edge(const Edge& e);
        void delete_edge(const index_t& start, const index_t& end);

        bool exists_edge(const Edge& e) const;
        bool exists_edge(const index_t& start, const index_t& end) const;


        EdgeSet get_outgoing_edges(const Node& n) const;
        EdgeSet get_outgoing_edges(const index_t& idx) const;

        EdgeSet get_incoming_edges(const Node& n) const;
        EdgeSet get_incoming_edges(const index_t& idx) const;


        void print_graph() const;
        std::vector<Node> breath_first_search(const Node& start) const;
        std::vector<Node> depth_first_search(const Node& start) const;

    private:
        NodeSet node_set;
        EdgeSet edge_set;

        OutgoingEdges outgoing_edges;
        IncomingEdges incoming_edges;

};
