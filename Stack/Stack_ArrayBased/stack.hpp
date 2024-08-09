#ifndef STACK_H
#define STACK_H

typedef int Type;

class Stack {

private:
    Type* arr;       // Pointer to the array holding stack elements
    int top;         // Index of the top element in the stack
    int size;        // Current number of elements in the stack
    int capacity;    // Maximum number of elements the stack can hold
    bool flag;       // If true, the stack can be resized; if false, it cannot

public:
    Stack();                 // Default constructor: Initializes stack with a default capacity and allows resizing
    Stack(int capacity);     // Parameterized constructor: Initializes stack with a given capacity and does not allow resizing
    ~Stack();                // Destructor to free allocated memory
    void push(Type value);   // Add a new element to the top of the stack
    void pop();              // Remove the top element from the stack
    Type peek();             // Get the top element without removing it
    int getSize();           // Get the current number of elements in the stack
    int getCapacity();       // Get the maximum capacity of the stack
    void resize();           // Resize the stack to increase capacity
    bool isEmpty();          // Check if the stack is empty
    bool isFull();           // Check if the stack is full
    void print();            // Print all elements in the stack

};

#endif // STACK_H
