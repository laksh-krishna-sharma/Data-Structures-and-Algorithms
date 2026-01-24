#ifndef QUEUE_HPP
#define QUEUE_HPP

class Node {
   public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:

    Node* front;
    Node* rear;
    int size;

public:
    Queue();

    ~Queue();

    void enqueue(int value);
    void dequeue();

    int peek() const;

    bool isEmpty() const;
    int getSize() const;

    void display() const;
};

#endif
