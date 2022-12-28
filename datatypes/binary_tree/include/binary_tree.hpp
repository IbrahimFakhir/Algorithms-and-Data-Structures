#pragma once

#include <treenode.hpp>
#include <memory>

class BinaryTree {

    public:
        BinaryTree(int root_data);

        TreeNodeptr get_root();
        
        void print_binary_tree();

    private:
        TreeNodeptr root;

};
