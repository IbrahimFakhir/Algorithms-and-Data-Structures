#pragma once

#include <treenode.hpp>
#include <memory>
#include <queue>
#include <iostream>

class BinarySearchTree {

    public:
        BinarySearchTree(int root_data);

        TreeNodeptr get_root();
        
        void insert_value(TreeNodeptr tree, int data);
        void delete_node(TreeNodeptr node);

        void preorder(TreeNodeptr root);
        void inorder(TreeNodeptr root);
        void postorder(TreeNodeptr root);
        void levelorder();

    private:
        TreeNodeptr root;

};
