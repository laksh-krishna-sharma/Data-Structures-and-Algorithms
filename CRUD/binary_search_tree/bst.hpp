#ifndef BST_HPP
#define BST_HPP

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

public:
    BST();
    ~BST();

    void insert(int val);
    bool search(int val) const;

    void deleteNode(Node* node);
    void display(Node* node) const;

    Node* getRoot() const;
};

#endif
