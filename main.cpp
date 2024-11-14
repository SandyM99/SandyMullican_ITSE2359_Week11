#include "OrderedCircularLinkedList.h"
#include "OrderedDoublyLinkedList.h"
#include <iostream>

int main() {
    OrderedCircularLinkedList circularList;
    OrderedDoublyLinkedList doublyList;

    int testData[] = {30, 25, 35, 20, 40};

    // Test Ordered Circular Linked List
    cout << "Ordered Circular Linked List:" << endl;
    for (int value : testData) {
        circularList.insertOrdered(value);
    }
    circularList.printList();

    // Test Ordered Doubly Linked List
    cout << "\nOrdered Doubly Linked List:" << endl;
    for (int value : testData) {
        doublyList.insertOrdered(value);
    }
    cout << "Forward: ";
    doublyList.printForward();
    cout << "Backward: ";
    doublyList.printBackward();

    return 0;
}
