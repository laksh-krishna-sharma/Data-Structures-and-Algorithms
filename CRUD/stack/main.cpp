#include "stack.hpp"
#include <iostream>
using namespace std;

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Stack elements: ";
    stack.display();

    cout << "Top element: " << stack.peek() << "\n";

    stack.pop();
    cout << "Stack elements after pop: ";
    stack.display();

    cout << "Current stack size: " << stack.getSize() << "\n";

    return 0;
}