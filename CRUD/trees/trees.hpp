#ifndef TREE_HPP
#define TREE_HPP

#include <vector>

struct TreeNode {
public:
    int data;
    std::vector<TreeNode*> children;

    explicit TreeNode(int value);
    ~TreeNode();
};

class Tree {
private:
    TreeNode* root;

    void deleteTree(TreeNode* node);

public:
    Tree();
    ~Tree();

    TreeNode* getRoot() const;
    TreeNode* createNode(int value);
    void setRoot(TreeNode* node);
    void addChild(TreeNode* parent, TreeNode* child);

    void display(TreeNode* node) const;
};

#endif // TREE_HPP
