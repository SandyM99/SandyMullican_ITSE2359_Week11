#ifndef ORDEREDDOUBLYLINKEDLIST_H
#define ORDEREDDOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class OrderedDoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    OrderedDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert function to maintain ascending order
    void insertOrdered(int newData) {
        DoublyNode* newNode = new DoublyNode(newData);

        // Case 1: List is empty
        if (!head) {
            head = tail = newNode;
            return;
        }

        // Case 2: Insert at the beginning
        if (newData <= head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        // Case 3: Insert in the middle or end
        DoublyNode* current = head;
        while (current->next && current->next->data < newData) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next) {
            current->next->prev = newNode;
        } else { // Insert at the end
            tail = newNode;
        }

        current->next = newNode;
    }

    // Print list forward
    void printForward() {
        DoublyNode* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Print list backward
    void printBackward() {
        DoublyNode* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

#endif
