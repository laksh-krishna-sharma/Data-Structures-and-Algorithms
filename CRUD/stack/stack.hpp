#ifndef STACK_HPP
#define STACK_HPP

class Node {
   public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = nullptr;
        }
};

class Stack {
    private:
    
        Node* top;
        int size;
    
    public:
        Stack();
        ~Stack();

        void push(int value);
        void pop();

        int peek() const;

        bool isEmpty() const;
        int getSize() const;
        
        void display() const;
};

#endif