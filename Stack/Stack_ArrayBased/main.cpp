#include "stack.hpp"

#include <iostream>
using namespace std;

int main() {
    // Create a stack with default constructor (resizable)
    Stack stack1;
    
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40); // Should trigger a resize

    cout << "Stack1 elements: ";
    stack1.print();

    cout << "Top element: " << stack1.peek() << endl;

    stack1.pop();
    cout << "Stack1 contents after popping: ";
    stack1.print();

    // Create a stack with a specific capacity (non-resizable)
    Stack stack2(3);

    stack2.push(1);
    stack2.push(2);
    stack2.push(3); 
    // Try pushing another element (should fail because it's full)
    stack2.push(4); // Should output "Stack is Full."

    cout << "Stack2 elements: ";
    stack2.print();

    cout << "Top element: " << stack2.peek() << endl;

    stack2.pop();
    cout << "Stack2 contents after popping: ";
    stack2.print(); 

    cout << "Stack1 Size: " << stack1.getSize() << endl;
    cout << "Stack1 Capacity: " << stack1.getCapacity() << endl;

    cout << "Stack2 Size: " << stack2.getSize() << endl;
    cout << "Stack2 Capacity: " << stack2.getCapacity() << endl;

    return 0;
}

