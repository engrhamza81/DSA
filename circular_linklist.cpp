#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node with data
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor initializes an empty list
    CircularLinkedList() : head(nullptr) {}

    // Insert a node at the beginning of the circular linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) { // If the list is empty
            head = newNode;
            newNode->next = head; // Point new node to itself
        } else {
            Node* temp = head;
            // Traverse to the last node to update its next pointer
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head; // Point new node to current head
            temp->next = newNode; // Last node points to new node
            head = newNode;       // Update head to new node
        }
    }

    // Insert a node at the end of the circular linked list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) { // If the list is empty
            head = newNode;
            newNode->next = head; // Point new node to itself
        } else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode; // Last node points to new node
            newNode->next = head; // New node points to head
        }
    }

    // Delete a node with a specific value
    void deleteNode(int value) {
        if (head == nullptr) return; // If list is empty, do nothing

        Node* temp = head;
        Node* prev = nullptr;

        // Check if head node contains the value
        if (head->data == value) {
            // Find the last node to update its next pointer
            while (temp->next != head) {
                temp = temp->next;
            }
            if (head->next == head) { // Only one node in the list
                delete head;
                head = nullptr;
            } else {
                temp->next = head->next; // Last node points to next of head
                Node* toDelete = head;
                head = head->next;       // Move head to the next node
                delete toDelete;
            }
            return;
        }

        // Traverse to find the node to delete
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != value);

        // If the node with value is found
        if (temp->data == value) {
            prev->next = temp->next;
            delete temp;
        }
    }

    // Display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    // Insert nodes at the end
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "List after inserting at the end: ";
    list.display();

    // Insert nodes at the beginning
    list.insertAtBeginning(5);
    list.insertAtBeginning(1);

    cout << "List after inserting at the beginning: ";
    list.display();

    // Delete a node
    list.deleteNode(20);

    cout << "List after deleting 20: ";
    list.display();

    return 0;
}
