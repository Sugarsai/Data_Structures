#include "queue.hpp"

#include <iostream>
using namespace std;

#define end "\n"

Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

void Queue::enqueue(Type value) {
    Node* node = new Node(value);
    if (!front) {
        front = rear = node; 
    } else {
        rear->next = node;
        rear = node;
    }
    ++size;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty." << end;
    }
    Node* temp = front;
    front = front->next;
    if (!front) {
        rear = nullptr;
    }
    delete temp;
    --size;
}

Type Queue::peek() {
    return front->data;
}

int Queue::getSize() {
    return size;
}

bool Queue::isEmpty() {
    return (size == 0);

}

void Queue::print() {
    Node* cur = front;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << end;
}
