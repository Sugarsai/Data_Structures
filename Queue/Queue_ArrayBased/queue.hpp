#ifndef QUEUE_H
#define QUEUE_H

typedef int Type;

class Queue {

private:
    Type* arr;       // Pointer to the array holding queue elements
    int front;       // Index of the front element in the queue
    int rear;        // Index of the rear element in the queue
    int size;        // Current number of elements in the queue
    int capacity;    // Maximum number of elements the queue can hold
    bool flag;       // If true, the queue can be resized; if false, it cannot
    
public:
    Queue();                   // Default constructor: Initializes queue with a default capacity and allows resizing
    Queue(int capacity);       // Parameterized constructor: Initializes queue with a given capacity and does not allow resizing
    ~Queue();                  // Destructor to free allocated memory
    void enqueue(Type value);  // Add a new element to the end of the queue
    void dequeue();            // Remove the first element from the queue
    Type peek();               // Get the first element without removing it
    int getSize();             // Get the current number of elements in the queue
    int getCapacity();         // Get the maximum capacity of the queue
    void resize();             // Resize the queue to increase capacity
    bool isFull();             // Check if the queue is full
    bool isEmpty();            // Check if the queue is empty
    void print();              // Print all elements in the queue

};

#endif // QUEUE_H
