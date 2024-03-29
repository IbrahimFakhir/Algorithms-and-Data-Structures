#include <binary_search_tree.hpp>
#include <treenode.hpp>

BinarySearchTree::BinarySearchTree(int root_data) {

    root = std::make_shared<TreeNode>(root_data);

}

TreeNodeptr BinarySearchTree::get_root() {

    return root;

}

void BinarySearchTree::insert_value(TreeNodeptr tree, int data) {
    // 1. case: tree is empty
    if (!tree) {
        tree->set_data(data);
        return;
    }
    // 2. case: given number is smaller than root of current tree
    if (data < tree->get_data()) {
        if (!tree->get_left_child()) {
            tree->set_left_child(data);
        }
        else {
            insert_value(tree->get_left_child(), data);
        }
    }
    // 3. case: given number is larger than root of current tree
    if (data > tree->get_data()) {
        if (!tree->get_right_child()) {
            tree->set_right_child(data);
        }
        else {
            insert_value(tree->get_right_child(), data);
        }
    }



}

void BinarySearchTree::preorder(TreeNodeptr root) {

    if (!root) {
        return;
    }
    std::cout << root->get_data() << " ";
    preorder(root->get_left_child());
    preorder(root->get_right_child());

}
void BinarySearchTree::inorder(TreeNodeptr root) {

    if (!root) {
        return;
    }

    inorder(root->get_left_child());
    std::cout << root->get_data() << " ";
    inorder(root->get_right_child());

}
void BinarySearchTree::postorder(TreeNodeptr root) {

    if (!root) {
        return;
    }
    postorder(root->get_left_child());
    postorder(root->get_right_child());
    std::cout << root->get_data() << " ";

}
void BinarySearchTree::levelorder() {

    std::queue<TreeNodeptr> queue;  

    queue.push(root);

    while(!queue.empty()) {
        TreeNodeptr node = queue.front();
        TreeNodeptr left = node->get_left_child();
        TreeNodeptr right = node-> get_right_child();
        
        if(left != nullptr) {
            queue.push(left);
        }
        if(right != nullptr) {
            queue.push(right);
        }

        queue.pop();
        std::cout << node->get_data() << " ";
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

TreeNodeptr TreeNode::get_parent() {

    return parent.lock();

}
void TreeNode::set_parent(const std::shared_ptr<TreeNode>& new_parent) {

    parent = new_parent;

}

