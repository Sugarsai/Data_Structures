#ifndef STACK_H
#define STACK_H

typedef int Type;

struct Node {
    Type data;        // Data stored in the node 
    Node* next;       // Pointer to the next node in the stack

    Node(Type data) : data(data), next(nullptr) {}
};

class Stack {

private:
    Node* top;       // Pointer to the top node of the stack
    int size;        // Current number of elements in the stack

public:
    Stack();                 // Constructor to initialize an empty stack
    void push(Type value);   // Add a new element to the top of the stack
    void pop();              // Remove the top element from the stack
    Type peek();             // Get the top element without removing it
    int getSize();           // Get the current number of elements in the stack
    bool isEmpty();          // Check if the stack is empty
    void print();            // Print all elements in the stack

};

#endif // STACK_H

