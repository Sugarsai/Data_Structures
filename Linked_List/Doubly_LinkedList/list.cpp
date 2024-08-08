#include "list.hpp"

#include <algorithm>
#include <iostream>
using namespace std;

#define end "\n"

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head->next;
        delete head;
        head = temp;
        size--;
    }
}

int LinkedList::getSize() {
    return size;
}

Node* LinkedList::front() {
    return head;
} 

Node* LinkedList::back() {
    return tail;
}

Node* LinkedList::max() {
    Node* cur = head;
    Node* max = cur;
    for (; cur; cur = cur->next) {
        if ((cur->data) > (max->data)) {
            max = cur;
        }
    }
    return max;
}

Node* LinkedList::min() {
    Node* cur = head;
    Node* min = head;
    for(; cur; cur = cur->next) {
        if ((cur->data) < (min->data)) {
            min = cur;
        }
    }
    return min;
}

void LinkedList::print() {
    for (Node* cur = head; cur; cur = cur->next) {
        cout << cur->data << " ";
    }
    cout << end;
}

void LinkedList::print_reversed() {
    for (Node* cur = tail; cur; cur = cur->prev) {
        cout << cur->data << " ";
    }
    cout << end;
}

void LinkedList::assign(int count, Type value) {
    if (count <= 0) {
        return;
    }
    for (int i = 0; i < count; i++) {
        insert_end(value);
    }
}

void LinkedList::insert(int idx, Type value) {
    if (idx < 0 || idx > size) {
        cout << "Index out of bounds" << end;
        return;
    }
    Node* node = new Node(value);
    if (idx == 0) {
        node->next = head;
        if (head != nullptr) {
            head->prev = node;
        }
        head = node;
        if (size == 0) {
            tail = node;
        }
    } else {
        Node* prev = head;
        for (int i = 0; i < idx - 1; i++) {
            prev = prev->next;
        }
        node->next = prev->next;
        if (prev->next != nullptr) {
            prev->next->prev = node;
        }
        prev->next = node;
        node->prev = prev;
        if (idx == size) {
            tail = node;
        }
    }
    size++;
}

void LinkedList::insert_front(Type value) {
    Node* node = new Node(value);
    if (!head) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    size++;
}

void LinkedList::insert_end(Type value) {
    Node* node = new Node(value);
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    size++;
}

void LinkedList::Delete(int idx) {
    if (idx < 0 || idx >= size) {
        cout << "Index out of bounds" << end;
        return;
    }
    Node* temp;
    if (idx == 0) {
        temp = head;
        head = head->next;
        if (size == 1) {
            tail = nullptr;
        }
        delete temp;
    } else {
        Node* prev = nullptr;
        Node* cur = head;
        for (int i = 0; i < idx; i++) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        cur->next->prev = prev;
        if (idx == size - 1) {
            tail = prev;
        }
        delete cur;
    }
    size--;
}

void LinkedList::Remove(Type value) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        if (cur->data == value) {
            if (cur == head) {
                head = head->next;
                if (!head) {
                    tail = nullptr;
                }
                delete cur;
                cur = head;
            } else {
                prev->next = cur->next;
                cur->next->prev = prev;
                if (cur == tail) {
                    tail = prev;
                }
                delete cur;
                cur = prev->next;
            }
            size--;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

int LinkedList::search(Type value) {
    int idx = 0;
    for (Node* cur = head; cur; cur = cur->next, idx++) {
        if (cur->data == value) {
            return idx;
        }
    }
    return -1;
}
