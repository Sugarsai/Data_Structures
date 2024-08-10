#include "queue.hpp"

#include <iostream>
using namespace std;

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue elements: ";
    queue.print();

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    cout << "Queue contents after dequeuing the front element: ";
    queue.print();

    cout << "Current queue size: " << queue.getSize() << endl;

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl; 

    queue.dequeue();
    queue.dequeue();
    cout << "Queue contents after dequeuing all elements: ";
    queue.print(); 

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl; 

    return 0;
}

