#include "list.hpp"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
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
    Node* min = cur;
    for (; cur; cur = cur->next) {
        if ((cur->data) < (min->data)) {
            min = cur;
        }
    }
    return min;
}

Node* LinkedList::get_nth(int pos) {
    if (pos <= 0 || pos > size) {
        cout << "Index out of bounds" << end;
        return nullptr;
    }
    int count = 0;
    for (Node* cur = head; cur; cur = cur->next) {
        if (++count == pos) {
            return cur;
        }
    }
    return nullptr;
}

Node* LinkedList::get_nth_fromBack(int pos) {
    if (pos <= 0 || pos > size) {
        cout << "Index out of bounds" << end;
        return nullptr;
    }
    int target = size - pos + 1;
    return get_nth(target);
}

void LinkedList::print() {
    for (Node* cur = head; cur; cur = cur->next) {
        cout << cur->data << " ";
    }
    cout << end;
}

void LinkedList::reverse() {
    if (!head || !head->next) {
        return;
    }
    Node* prev = nullptr;
    Node* cur = head;
    Node* next = nullptr;
    tail = head; 

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;
}

void LinkedList::sort() {
    if (!head || !head->next) {
        return;
    }
    bool swapped;
    do {
        swapped = false;
        Node* cur = head;
        while (cur && cur->next) {
            if ((cur->data) > (cur->next->data)) {
                Type temp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = temp;
                swapped = true;
            }
            cur = cur->next;
        }
    } while (swapped);
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
        prev->next = node;
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

void LinkedList::merge(LinkedList& other) {
    if (!other.head) {
        return;
    }
    if (!head) {
        head = other.head;
        tail = other.tail;
    } else {
        this->tail->next = other.head;
        this->tail = other.tail;
    }

    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}

bool LinkedList::isSame(const LinkedList& other) const {
    if (this->size != other.size) {
        return false;
    }
    Node* cur = head;
    Node* cur2 = other.head;

    while (cur && cur2) {
        if (cur->data != cur2->data) {
            return false;
        }
        cur = cur->next;
        cur2 = cur2->next;
    }
    return (cur == nullptr) && (cur2 == nullptr);
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

void LinkedList::verifyDataIntegrity() {
    if (size == 0) {
        assert(head == nullptr);
        assert(tail == nullptr);
    } else {
        assert(head != nullptr);
        assert(tail != nullptr);
        if (size == 1) {
            assert(head == tail);
        } else {
            assert(head != tail);
        }
        assert(!tail->next);
    }
}

