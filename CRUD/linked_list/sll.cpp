#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

class SinglyLinkedList {
   private:
    Node* head;

   public:
    // Constructor
    SinglyLinkedList() { head = NULL; }

    // Insert at End
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at Beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insert at Position
    void insertAtPosition(int pos, int data) {
        if (pos < 0) {
            cout << "Invalid Position\n";
            return;
        }
        if (pos == 0) {
            insertAtBeginning(data);
            return;
        }
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp != NULL && i < pos - 1) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Read
    void display() const {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Update
    void update(int pos, int data) {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp != NULL && i < pos) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }
        temp->val = data;
    }

    // Delete
    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        if (pos == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp->next != NULL && i < pos - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    ~SinglyLinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* newNode = temp->next;
            delete temp;
            temp = newNode;
        }
    }
};

int main() {
    SinglyLinkedList list;

    // CREATE
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtPosition(1, 7);

    // READ
    list.display();

    // UPDATE
    list.update(1, 15);

    list.display();

    // DELETE
    list.deleteAtPosition(1);

    list.display();

    return 0;
}
