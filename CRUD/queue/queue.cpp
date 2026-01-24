#include <bits/stdc++.h>
#include "queue.hpp"
using namespace std;

Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    size++;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }

    Node* temp = front;
    front = front->next;
    delete temp;

    if (front == nullptr) {
        rear = nullptr;
    }

    size--;
}

int Queue::peek() const {
    if (isEmpty()) {
        cout << "Queue is empty. No front element.\n";
        return -1;
    }
    return front->data;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}

int Queue::getSize() const {
    return size;
}

void Queue::display() const {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << "\n";
    cout << "Size: " << q.getSize() << "\n";

    return 0;
}
