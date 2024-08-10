#include "queue.hpp"

#include <iostream>
using namespace std;

int main() {
    // Create a queue with default constructor (resizable)
    Queue queue1;
    
    queue1.enqueue(10);
    queue1.enqueue(20);
    queue1.enqueue(30);
    queue1.enqueue(40);
    queue1.enqueue(50);
    queue1.enqueue(60); // Should trigger a resize

    cout << "Queue1 elements: ";
    queue1.print();

    cout << "Front element: " << queue1.peek() << endl;

    queue1.dequeue();
    cout << "Queue1 contents after dequeuing: ";
    queue1.print();

    // Create a queue with a specific capacity (non-resizable)
    Queue queue2(3);

    queue2.enqueue(1);
    queue2.enqueue(2);
    queue2.enqueue(3);
    // Try enqueueing another element (should fail because it's full)
    queue2.enqueue(4); // Should output "Queue is Full."

    cout << "Queue2 elements: ";
    queue2.print();

    cout << "Front element: " << queue2.peek() << endl;

    queue2.dequeue();
    cout << "Queue2 contents after dequeuing: ";
    queue2.print();

    cout << "Queue1 Size: " << queue1.getSize() << endl;
    cout << "Queue1 Capacity: " << queue1.getCapacity() << endl;

    cout << "Queue2 Size: " << queue2.getSize() << endl;
    cout << "Queue2 Capacity: " << queue2.getCapacity() << endl;

    return 0;
}

