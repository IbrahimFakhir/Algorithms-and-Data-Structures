#include <binary_search_tree.hpp>
#include <treenode.hpp>





TreeNode::TreeNode(int new_data) {

    data = new_data;

    left_child = nullptr;
    right_child = nullptr;

}

void TreeNode::set_data(int new_data) {

    data = new_data;

}
int TreeNode::get_data() {

    return data;

}

TreeNodeptr TreeNode::get_left_child() {

    return left_child;

}
TreeNodeptr TreeNode::get_right_child() {

    return right_child;

}

void TreeNode::set_left_child(int new_data) {

    if (left_child) {
        left_child->set_data(new_data);
    }
    else {
        left_child = std::make_shared<TreeNode>(new_data);
    }

}
void TreeNode::set_right_child(int new_data) {

    if (right_child) {
        right_child->set_data(new_data);
    }
    else {
        right_child = std::make_shared<TreeNode>(new_data);
    }

}

void TreeNode::remove_left_child() {

    left_child = nullptr;

}
void TreeNode::remove_right_child() {

    right_child = nullptr;

}

TreeNodeptr TreeNode::get_parent() {

    return parent.lock();

}
void TreeNode::set_parent(const std::shared_ptr<TreeNode>& new_parent) {

    parent = new_parent;

}

