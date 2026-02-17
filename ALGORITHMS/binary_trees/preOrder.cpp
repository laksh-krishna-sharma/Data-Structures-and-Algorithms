#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        right = left = NULL;
    }
};

void preOrder(Node* root){

    if(root == NULL){
        return;
    }

    cout << root->data << "->";
    preOrder(root->left);
    preOrder(root->right);

    return;
}

int main() {
    /*
        Create binary tree
              1
            /  \
           2    3
          / \     \
         4   5     6
     */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    preOrder(root);

    return 0;
}
