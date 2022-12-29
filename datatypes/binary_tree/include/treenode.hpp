#pragma once

#include <memory>

class TreeNode {

    public:
        TreeNode(int data);

        void set_data(int new_data);
        int get_data();

        std::shared_ptr<TreeNode> get_left_child();
        std::shared_ptr<TreeNode> get_right_child();

        void set_left_child(int new_data);
        void set_right_child(int new_data);

        void remove_left_child();
        void remove_right_child();

        std::shared_ptr<TreeNode> get_parent();
        void set_parent(const std::shared_ptr<TreeNode>& new_parent);

    private:
        int data;

        std::shared_ptr<TreeNode> left_child;
        std::shared_ptr<TreeNode> right_child;

        std::shared_ptr<TreeNode> parent;

};

typedef std::shared_ptr<TreeNode> TreeNodeptr;
