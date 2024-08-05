#ifndef LIST_H
#define LIST_H

typedef int Type;

struct Node {
    Type data;        // Data stored in the node 
    Node* next;       // Pointer to the next node in the list

    Node(Type data) : data(data), next(nullptr) {}
};

class LinkedList {

private: 
    Node* head;       // Pointer to the first node in the list
    Node* tail;       // Pointer to the last node in the list
    int size;         // Number of elements in the list

public:
    LinkedList();     // Constructor initializes an empty list
    ~LinkedList();    // Destructor to clean up the linked list

    int getSize();                      // Returns the number of elements in the list

    Node* front();                      // Returns a pointer to the first node
    Node* back();                       // Returns a pointer to the last node
    Node* max();                        // Finds and returns a pointer to the node with the maximum value
    Node* min();                        // Finds and returns a pointer to the node with the minimum value
    Node* get_nth(int pos);             // Returns a pointer to the node at the specified position (1-based index)
    Node* get_nth_fromBack(int pos);    // Returns a pointer to the node at the specified position from the end (1-based index)

    void print();                       // Prints all elements in the list
    void sort();                        // Sorts the list in ascending order
    void reverse();                     // Reverses the order of elements in the list
    void assign(int count, Type value); // Adds 'count' number of nodes with the given value to the end of the list
    void insert(int idx, Type value);   // Inserts a new node at the specified index
    void insert_front(Type value);      // Inserts a new node at the beginning of the list
    void insert_end(Type value);        // Inserts a new node at the end of the list
    void Delete(int idx);               // Deletes the node at the specified index
    void Remove(Type value);            // Removes all nodes with the given value from the list
    void merge(LinkedList& other);      // Merges another linked list into this one
    bool isSame(const LinkedList& other) const;   // Checks if this list is identical to another list
    int search(Type value);             // Searches for a node with the given value and returns its index, or -1 if not found
    void verifyDataIntegrity();         // Verifies the integrity of the linked list structure};

};

#endif // LIST_H
