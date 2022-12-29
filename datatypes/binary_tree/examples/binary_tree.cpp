#include <binary_tree.hpp>

#include <iostream>

int main() {

    // initialize tree
    BinaryTree t = BinaryTree(42);
    TreeNodeptr root = t.get_root();

    // left tree
    root->set_left_child(11);
    TreeNodeptr first_left = root->get_left_child();
    first_left->set_left_child(9);
    first_left->set_right_child(0);
    TreeNodeptr second_left = first_left->get_left_child();
    second_left->set_left_child(-6);
    second_left->set_right_child(22);

    // right tree
    root->set_right_child(22);
    TreeNodeptr first_right = root->get_right_child();
    first_right->set_right_child(544);
    TreeNodeptr second_right = first_right->get_right_child();
    second_right->set_left_child(11);

    // start printing
    std::cout << "\nPreorder:\t";
    t.preorder(root);
    std::cout << "\nInorder:\t";
    t.inorder(root);
    std::cout << "\nPostorder:\t";
    t.postorder(root);
    std::cout << "\nLevelorder:\t";
    t.levelorder();

}
