#ifndef ORDEREDCIRCULARLINKEDLIST_H
#define ORDEREDCIRCULARLINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class OrderedCircularLinkedList {
private:
    Node* head;

public:
    OrderedCircularLinkedList() : head(nullptr) {}

    // Insert function to maintain ascending order
    void insertOrdered(int newData) {
        Node* newNode = new Node(newData);

        // Case 1: List is empty
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }

        // Case 2: Insert before head (smallest element) or in correct position
        Node* current = head;
        Node* prev = nullptr;

        do {
            if (current->data >= newData) break;
            prev = current;
            current = current->next;
        } while (current != head);

        if (!prev) {  // Inserting as new head
            newNode->next = head;
            head = newNode;

            // Find last node to complete circular link
            Node* temp = head;
            while (temp->next != current) temp = temp->next;
            temp->next = head;
        } else {
            prev->next = newNode;
            newNode->next = current;

            // If we're at the end of the list, make it circular
            if (current == head) newNode->next = head;
        }
    }

    // Print function to display the circular list
    void printList() {
        if (!head) return;
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

#endif
