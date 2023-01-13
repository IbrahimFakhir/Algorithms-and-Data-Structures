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
        size_t operator() (const Node& k) const;

};
typedef std::unordered_set<Node, NodeHash> NodeSet;

class EdgeHash {

    public:
        size_t operator() (const Edge& k) const;

};
typedef std::unordered_set<Edge, EdgeHash> EdgeSet;

class DirectedGraph {

    public:
        DirectedGraph();

        

};
