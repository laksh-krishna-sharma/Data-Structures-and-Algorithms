#include "trees.hpp"
#include <iostream>

int main() {
    Tree tree;

    // Create nodes
    TreeNode* root = tree.createNode(1);
    TreeNode* child1 = tree.createNode(2);
    TreeNode* child2 = tree.createNode(3);
    TreeNode* child3 = tree.createNode(4);
    TreeNode* subChild1 = tree.createNode(5);
    TreeNode* subChild2 = tree.createNode(6);

    // Build tree
    tree.setRoot(root);
    tree.addChild(root, child1);
    tree.addChild(root, child2);
    tree.addChild(root, child3);
    tree.addChild(child1, subChild1);
    tree.addChild(child1, subChild2);

    // Traversals
    std::cout << "Traversal: ";
    tree.display(tree.getRoot());


    return 0;
}

/*
        1
      / | \  
    2   3  4
   / \
  5  6
Traversal: 1 2 5 6 3 4
*/ 