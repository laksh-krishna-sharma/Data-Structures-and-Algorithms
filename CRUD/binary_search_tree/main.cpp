#include <iostream>
#include "bst.hpp"

using namespace std;

int main() {
    BST tree;

    // Insert elements
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);
    tree.insert(12);
    tree.insert(20);

    // Display BST (inorder traversal)
    cout << "BST traversal: ";
    tree.display(tree.getRoot());
    cout << endl;

    // Search tests
    cout << "Search 7  : " << (tree.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search 13 : " << (tree.search(13) ? "Found" : "Not Found") << endl;

    return 0;
}

/*
          10
         /  \
        5    15
       / \   / \
      2   7 12 20

Output:
BST traversal: 2 5 7 10 12 15 20
Search 7  : Found
Search 13 : Not Found
*/