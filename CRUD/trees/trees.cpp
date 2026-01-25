#include "trees.hpp"
#include <bits/stdc++.h>

/* ---------- TreeNode ---------- */

TreeNode::TreeNode(int value) : data(value) {}

TreeNode::~TreeNode() {
    // children are deleted by Tree's deleteTree()
}

/* ---------- Tree ---------- */

Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
    deleteTree(root);
}

void Tree::deleteTree(TreeNode* node) {
    if (!node) return;

    for (TreeNode* child : node->children) {
        deleteTree(child);
    }
    delete node;
}

TreeNode* Tree::createNode(int value) {
    return new TreeNode(value);
}

void Tree::setRoot(TreeNode* node) {
    root = node;
}

TreeNode* Tree::getRoot() const {
    return root;
}

void Tree::addChild(TreeNode* parent, TreeNode* child) {
    if (parent) {
        parent->children.push_back(child);
    } 
}

/* ---------- Traversals ---------- */

void Tree::display(TreeNode* node) const {
    if (!node) return;

    std::cout << node->data << " ";

    for (TreeNode* child : node->children) {
        display(child);
    }
}

