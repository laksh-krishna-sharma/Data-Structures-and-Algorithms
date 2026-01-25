#include "bst.hpp"
#include <bits/stdc++.h>
using namespace std;

BST::BST() : root(nullptr) {}

BST::~BST() {
    deleteNode(root);
}

void BST::deleteNode(Node* node){
    if (node) {
        deleteNode(node->left);
        deleteNode(node->right);
        delete node;
    }
}

void BST::insert(int val) {
    Node* newNode = new Node(val);

    if (!root) {
        root = newNode;
        return;
    }

    Node* curr = root;

    while (true) {
        if (val < curr->data) {
            if (curr->left) {
                curr = curr->left;
            } else {
                curr->left = newNode;
                break;
            }
        } else {
            if (curr->right) {
                curr = curr->right;
            } else {
                curr->right = newNode;
                break;
            }
        }
    }
}


bool BST::search(int val) const {
    Node* curr = root;
    while (curr) {
        if (val < curr->data) {
            curr = curr->left;
        } else if (val > curr->data) {
            curr = curr->right;
        } else {
            return true; // Value found
        }
    }
    return false; // Value not found
}

Node* BST::getRoot() const {
    return root;
}

void BST::display(Node* node) const {
    if (node) {
        display(node->left);
        cout << node->data << " ";
        display(node->right);
    }
}
