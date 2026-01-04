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

class CircularLinkedList {
   private:
    Node* head;

   public:
    // Constructor: Initializes the head to NULL
    CircularLinkedList() { head = NULL; }

    // Insert at End: Adds a new node at the end of the circular linked list
    // If the list is empty, the new node becomes the head and points to itself
    // Otherwise, traverses to the last node and inserts the new node there, updating pointers
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;  // Points to itself since it's circular
            return;
        }

        Node* temp = head;
        while (temp->next != head) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;  // New node points back to head
    }

    // Insert at Beginning: Adds a new node at the beginning of the circular linked list
    // The new node points to the current head, and the last node is updated to point to the new head
    // If the list is empty, it behaves like insertAtEnd
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {  // Find the last node
            temp = temp->next;
        }

        newNode->next = head;  // New node points to old head
        temp->next = newNode;  // Last node points to new node
        head = newNode;        // Update head
    }

    // Insert at Position: Inserts a new node at a specified position (0-based index)
    // Handles edge cases: invalid position, empty list, position 0 (calls insertAtBeginning)
    // Traverses to the position and inserts the node, updating pointers
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

        while (temp->next != head && i < pos - 1) {  // Traverse to position-1
            temp = temp->next;
            i++;
        }
        if (i != pos - 1) {  // If position is beyond the list
            cout << "Invalid Position\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Display: Prints all elements in the circular linked list
    // Starts from head and stops when it comes back to head
    // Handles empty list case
    void display() const {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->val << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";  // Indicate circular nature
    }

    // Update: Updates the value at a specified position (0-based index)
    // Traverses to the position and changes the value
    // Handles empty list and invalid position
    void update(int pos, int data) {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        int i = 0;

        do {
            if (i == pos) {
                temp->val = data;
                return;
            }
            temp = temp->next;
            i++;
        } while (temp != head);

        cout << "Invalid Position\n";
    }

    // Delete at Position: Deletes the node at a specified position (0-based index)
    // Handles edge cases: empty list, position 0 (update head and last node pointer)
    // Traverses to the position, deletes the node, and updates pointers
    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is Empty\n";
            return;
        }

        if (pos == 0) {
            if (head->next == head) {  // Only one node
                delete head;
                head = NULL;
                return;
            }
            Node* temp = head;
            while (temp->next != head) {  // Find last node
                temp = temp->next;
            }
            Node* toDelete = head;
            head = head->next;
            temp->next = head;  // Update last node's next
            delete toDelete;
            return;
        }

        Node* temp = head;
        int i = 0;

        while (temp->next != head && i < pos - 1) {  // Traverse to position-1
            temp = temp->next;
            i++;
        }

        if (temp->next == head || i != pos - 1) {  // Invalid position
            cout << "Invalid Position\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // Destructor: Frees all nodes in the circular linked list
    // Traverses the list and deletes each node
    ~CircularLinkedList() {
        if (head == NULL) return;

        Node* temp = head;
        Node* nextNode;
        do {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
    }
};

int main() {
    CircularLinkedList list;

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