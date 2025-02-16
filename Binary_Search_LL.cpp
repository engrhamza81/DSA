#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Helper function to insert a node at the end of the list
void insertNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Simplified binary search function on a linked list
Node* binarySearchLinkedList(Node* head, int target) {
    Node* start = head;
    Node* end = nullptr;

    while (start != end) {
        // Find middle node
        Node* mid = start;
        Node* fast = start;
        while (fast != end && fast->next != end) {
            mid = mid->next;
            fast = fast->next->next;
        }

        // Check if mid node is the target
        if (mid->data == target) return mid;
        else if (mid->data < target) start = mid->next; // Move start to right half
        else end = mid; // Move end to left half
    }
    return nullptr; // Target not found
}

int main() {
    Node* head = nullptr;

    // Create a sorted linked list
    insertNode(head, 2);
    insertNode(head, 5);
    insertNode(head, 8);
    insertNode(head, 12);
    insertNode(head, 16);
    insertNode(head, 23);
    insertNode(head, 38);
    insertNode(head, 56);
    insertNode(head, 72);
    insertNode(head, 91);

    int target = 23;
    Node* result = binarySearchLinkedList(head, target);

    if (result) {
        cout << "Element found: " << result->data << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}
