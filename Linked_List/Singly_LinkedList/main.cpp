#include "list.hpp"

#include <iostream>
using namespace std;

int main() {
    LinkedList list1;
    list1.insert_end(3);
    list1.insert_end(1);
    list1.insert_end(4);
    list1.insert_end(2);
    
    cout << "Elements in List 1: ";
    list1.print();
    
    cout << "Size of List 1: " << list1.getSize() << endl;
    cout << "Front element: " << list1.front()->data << endl;
    cout << "Back element: " << list1.back()->data << endl;
    
    cout << "Maximum element: " << list1.max()->data << endl;
    cout << "Minimum element: " << list1.min()->data << endl;
    
    list1.sort();
    cout << "Sorted elements in List 1: ";
    list1.print();
    
    list1.insert(2, 5);
    cout << "List 1 after insertion at index 2: ";
    list1.print();
    
    list1.insert_front(0);
    list1.insert_end(6);
    cout << "List 1 after insertions at the front and back: ";
    list1.print();
    
    cout << "Element at position 3: " << list1.get_nth(3)->data << endl;
    cout << "Element at position 2 from the back: " << list1.get_nth_fromBack(2)->data << endl;
    
    list1.Delete(1);
    cout << "List 1 after deleting element at index 1: ";
    list1.print();
    
    list1.Remove(5);
    cout << "List 1 after removing all elements with value 5: ";
    list1.print();

    int searchValue = 4;
    int index = list1.search(searchValue);
    if (index != -1) {
        cout << "Value " << searchValue << " found at index " << index << endl;
    } else {
        cout << "Value " << searchValue << " not found" << endl;
    }
    
    LinkedList list2;
    list2.insert_end(10);
    list2.insert_end(20);
    list2.insert_end(30);
    cout << "Elements in List 2: ";
    list2.print();
    
    list1.merge(list2);
    cout << "List 1 after merging with List 2: ";
    list1.print();
    
    LinkedList list3;
    list3.insert_end(1);
    list3.insert_end(2);
    list3.insert_end(3);
    cout << "Is List 1 the same as List 3? " << (list1.isSame(list3) ? "Yes" : "No") << endl;
    
    list1.verifyDataIntegrity();
    cout << "Data integrity has been verified." << endl;

    return 0;
}

