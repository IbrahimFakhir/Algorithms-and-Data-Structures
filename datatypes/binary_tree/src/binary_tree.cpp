#include <binary_tree.hpp>
#include <treenode.hpp>

BinaryTree::BinaryTree(int root_data) {

    root = std::make_shared<TreeNode>(root_data);

}

TreeNodeptr BinaryTree::get_root() {

    return root;

}

void BinaryTree::print_binary_tree() {
    // printing by breath-first-search

    std::queue<TreeNodeptr> q;
    q.push(root);
    // print every element of the queue and add its children to queue
    while (q.size()) {
        for (int i = 0; i < q.size(); i++) {
            TreeNodeptr curr = q.front();
            if (curr) {
                std::cout << curr->get_data() << ",";

                q.push(curr->get_left_child());
                q.push(curr->get_right_child());
            }
            else {
                std::cout << "null,";
            }
            q.pop();
        }
        std::cout << std::endl;
    }

}

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
