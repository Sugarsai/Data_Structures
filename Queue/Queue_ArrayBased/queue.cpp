#include "queue.hpp"

#include <iostream>
#include <iterator>
using namespace std;

#define end "\n"

Queue::Queue() : front(0), rear(0), size(0), capacity(5), flag(1) {
    arr = new Type[capacity];
}

Queue::Queue(int capacity) : front(0), rear(0), size(0), capacity(capacity), flag(0) {
    arr = new Type[capacity];
}

Queue::~Queue() {
    delete [] arr;
}

void Queue::enqueue(Type value) {
    if (isFull()) {
        if (flag) {
            resize();
        } else {
            cout << "Queue is Full." << end;
            return;
        }
    }
    arr[rear] = value;
    rear = (rear + 1) % capacity;
    ++size;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty." << end;
        return;
    }
    front = (front + 1) % capacity;
    --size;
}

Type Queue::peek() {
    return arr[front];
} 

int Queue::getSize() {
    return size;
}

int Queue::getCapacity() {
    return capacity;
}

void Queue::resize() {
    int cap = capacity;
    capacity *= 2;
    Type* temp = new Type[capacity];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[(front + i) % cap];
    }
    swap(arr, temp);
    delete [] temp;
    front = 0;
    rear = size;
}

bool Queue::isFull() {
    return size == capacity;
}

bool Queue::isEmpty() {
    return (size == 0);
}

void Queue::print() {
    int cur = front;
    int i = 0;
    for (; i < size; i++, cur = (cur + 1) % capacity) {
        cout << arr[cur] << " ";
    }
    cout << end;
}
