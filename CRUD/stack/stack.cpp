#include "stack.hpp"

#include <bits/stdc++.h>
using namespace std;

Stack::Stack() : top(nullptr), size(0) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }
    size++;

    return;
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty. Cannot pop.\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;

    size--;

    return;
}

int Stack::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty. No top element.\n";
        return -1;
    }
    return top->data;
}

bool Stack::isEmpty() const { return top == nullptr; }

int Stack::getSize() const { return size; }

void Stack::display() const {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}
