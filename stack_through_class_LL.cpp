#include <iostream>
using namespace std;

// Node class representing each element in the stack
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize the node with a value
    Node(int value) : data(value), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() : top(nullptr) {}

    // Destructor to free memory when stack is destroyed
    ~Stack() {
        while (!isEmpty()) {
            pop();  // Free all nodes
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;  // Returns true if top is null
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);  // Create a new node
        newNode->next = top;               // Point new node to current top
        top = newNode;                     // Update top to new node
        cout << "Pushed " << value << " to the stack." << endl;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {  // Check if the stack is empty
            cout << "Stack is empty! Cannot pop." << endl;
            return -1;  // Return a sentinel value
        } else {
            Node* temp = top;              // Store the current top
            int poppedValue = top->data;   // Get the data from the top
            top = top->next;               // Move top to the next node
            delete temp;                   // Free the memory
            return poppedValue;            // Return the popped value
        }
    }

    // Function to read the top element of the stack
    int peek() {
        if (isEmpty()) {  // Check if the stack is empty
            cout << "Stack is empty! Cannot peek." << endl;
            return -1;  // Return a sentinel value
        } else {
            return top->data;  // Return the data of the top node
        }
    }
};

// Main function to demonstrate stack operations
int main() {
    Stack stack;  // Create a stack instance

    // Demonstrate stack operations
    stack.push(10);  // Push elements onto the stack
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;  // Peek the top element

    cout << "Popped: " << stack.pop() << endl;  // Pop the top element
    cout << "Top element after pop is: " << stack.peek() << endl;  // Peek again

    return 0;  // Indicate that the program ended successfully
}
