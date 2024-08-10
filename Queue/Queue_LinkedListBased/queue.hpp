#ifndef QUEUE_H
#define QUEUE_H

typedef int Type;

struct Node {
    Type data;        // Data stored in the node 
    Node* next;       // Pointer to the next node in the stack

    Node(Type data) : data(data), next(nullptr) {}
};

class Queue {

private:
    Node* front;      // Pointer to the front node of the queue 
    Node* rear;       // Pointer to the rear node of the queue 
    int size;         // Current number of elements in the queue
    
public:
    Queue();                   // Constructor to initialize an empty queue
    void enqueue(Type value);  // Add a new element to the end of the queue
    void dequeue();            // Remove the first element from the queue
    Type peek();               // Get the first element without removing it
    int getSize();             // Get the current number of elements in the queue
    bool isEmpty();            // Check if the queue is empty
    void print();              // Print all elements in the queue

};

#endif // QUEUE_H
