#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList{
    private:
    Node* head;
    Node* tail;

    public:
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtBeginning(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtPosition(int val, int pos){
        if(pos == 0){
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* current = head;
        for(int i = 0; i < pos - 1 && current; i++){
            current = current->next;
        }
        if(!current){
            insertAtEnd(val);
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if(current->next)
            current->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        current->next = newNode;
    }

    void updateNode(int oldVal, int newVal){
        Node* current = head;
        while(current){
            if(current->data == oldVal){
                current->data = newVal;
                return;
            }
            current = current->next;
        }
    }

    void deleteNode(int val){
        Node* current = head;
        while(current){
            if(current->data == val){
                if(current->prev)
                    current->prev->next = current->next;
                else
                    head = current->next; // Deleting head

                if(current->next)
                    current->next->prev = current->prev;
                else
                    tail = current->prev; // Deleting tail

                delete current;
                return;
            }
            current = current->next;
        }
    }

    void display(){
        Node* current = head;
        while(current){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor: Frees all nodes in the doubly linked list to prevent memory leaks
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        tail = NULL;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.insertAtPosition(15, 2);
    dll.display(); // Output: 5 10 15 20

    dll.updateNode(15, 17);
    dll.display(); // Output: 5 10 17 20

    dll.deleteNode(10);
    dll.display(); // Output: 5 17 20

    return 0;
}