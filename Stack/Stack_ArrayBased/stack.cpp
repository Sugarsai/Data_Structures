#include "stack.hpp"

#include <iostream>
#include <utility>
using namespace std;

#define end "\n"

Stack::Stack() : top(-1), size(0), capacity(3), flag(1) {
    arr = new Type[capacity];
}

Stack::Stack(int capacity) : top(-1), size(0), capacity(capacity), flag(0) {
    arr = new Type[capacity];
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(Type value) {
    if(isFull()) {
        if (flag) {
            resize();
        } else {
            cout << "Stack is Full." << end;
            return;
        }
    }
    arr[++top] = value;
    ++size;
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is Empty." << end;
        return;
    }
    --top;
    --size;
}

Type Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is Empty." << end;
    }
    return arr[top];
}

int Stack::getSize() {
    return size;
}

int Stack::getCapacity() {
    return capacity;
}

void Stack::resize() {
    capacity *= 2;
    Type* temp = new Type[capacity];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    swap(arr, temp);
    delete [] temp;
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return size == capacity;
}

void Stack::print() {
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << end;
}
