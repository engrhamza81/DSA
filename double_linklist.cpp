#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;  // Pointer to the previous node
    Node* next;  // Pointer to the next node

    // Constructor to easily create a new node
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;  // Pointer to the first node in the list

public:
    // Constructor initializes an empty list
    DoublyLinkedList() : head(nullptr) {}

    // Insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (head != nullptr) {
            head->prev = newNode;        // Link the old head's prev to the new node
            newNode->next = head;        // Link the new node's next to the old head
        }
        head = newNode;                  // Update the head to the new node
    }

    // Insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;// If list is empty, new node becomes the head
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;            // Link the last node's next to the new node
        newNode->prev = temp;            // Link the new node's prev to the last node
    }

    // Delete a node with a given value
    void deleteNode(int value) {
        if (head == nullptr) return;// If the list is empty, do nothing

        Node* temp = head;

        // Find the node with the given value
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) return;      // If the value is not found, do nothing

        // Adjust pointers to remove the node
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        if (temp == head) head = temp->next; // If the head is to be deleted, update it

        delete temp;                      // Free the memory of the node
    }

    // Display the list in forward order
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display the list in backward order
    void displayBackward() {
        if (head == nullptr) return;

        Node* temp = head;
        while (temp->next != nullptr) {  // Traverse to the last node
            temp = temp->next;
        }

        // Display from the last node back to the head
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Inserting nodes at the beginning
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    // Inserting nodes at the end
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "List in forward order: ";
    list.displayForward();

    cout << "List in backward order: ";
    list.displayBackward();

    // Deleting a node
    list.deleteNode(20);

    cout << "List after deleting 20: ";
    list.displayForward();

    return 0;
}
