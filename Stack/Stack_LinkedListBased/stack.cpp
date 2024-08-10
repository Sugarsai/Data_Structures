#include "stack.hpp"

#include <iostream>
using namespace std;

#define end "\n"

Stack::Stack() : top(nullptr), size(0) {}

void Stack::push(Type value) {
    Node* node = new Node(value);
    node->next = top;
    top = node;
    ++size;
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is Empty." << end;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    --size;
}

Type Stack::peek() {
    return top->data;
}

bool Stack::isEmpty() {
    return (size == 0);
}

int Stack::getSize() {
    return size;
}

void Stack::print() {
    Node* cur = top;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << end;
}
