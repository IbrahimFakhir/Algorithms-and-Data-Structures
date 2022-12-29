#pragma once

#include <treenode.hpp>
#include <memory>
#include <queue>
#include <iostream>

class BinaryTree {

    public:
        BinaryTree(int root_data);

        TreeNodeptr get_root();

        void preorder(TreeNodeptr root);
        void inorder(TreeNodeptr root);
        void postorder(TreeNodeptr root);
        void levelorder();

    private:
        TreeNodeptr root;

};
