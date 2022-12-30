#include <binary_search_tree.hpp>

#include <iostream>

int main() {

    BinarySearchTree t = BinarySearchTree(5);

    t.insert_value(t.get_root(), 3);
    t.insert_value(t.get_root(), 7);

    t.inorder(t.get_root());

}
