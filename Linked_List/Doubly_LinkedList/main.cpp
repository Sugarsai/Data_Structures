#include "list.hpp"

#include <iostream>
using namespace std;

int main() {
    LinkedList list;
    list.assign(3, 4);
    list.insert_end(6);
    list.insert_end(7);
    list.insert_front(1);
    
    cout << "List elements: ";
    list.print();

    cout << "List elements in reverse: ";
    list.print_reversed();
    
    cout << "Size of the List: " << list.getSize() << endl;
    cout << "Front element: " << list.front()->data << endl;
    cout << "Back element: " << list.back()->data << endl;
    
    cout << "Maximum element: " << list.max()->data << endl;
    cout << "Minimum element: " << list.min()->data << endl;
    
    list.insert(2, 5);
    cout << "List after insertion at index 2: ";
    list.print();
    
    list.insert_front(0);
    list.insert_end(8);
    cout << "List after insertions at the front and back: ";
    list.print();

    list.Delete(2);
    cout << "List after deleting element at index 2: ";
    list.print();
    
    list.Remove(4);
    cout << "List after removing all elements with value 4: ";
    list.print();

    int searchValue = 4;
    int index = list.search(searchValue);
    if (index != -1) {
        cout << "Value " << searchValue << " found at index " << index << endl;
    } else {
        cout << "Value " << searchValue << " not found" << endl;
    }

    return 0;
}
