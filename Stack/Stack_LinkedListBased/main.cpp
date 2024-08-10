#include "stack.hpp"

#include <iostream>
using namespace std;

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack elements: ";
    stack.print();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    cout << "Stack contents after popping top element: ";
    stack.print();

    cout << "Current stack size: " << stack.getSize() << endl;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; 

    stack.pop();
    stack.pop();
    cout << "Stack contents after popping all elements: ";
    stack.print(); 

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; 

    return 0;
}

