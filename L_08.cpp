#include <iostream>
using namespace std;

const int n = 5;  // Maximum size of the stack
int stack[n];     // Array to hold stack elements
int top = -1;     // Initialize top to -1 (stack is empty)

// Function to push an element onto the stack
void push(int value) {
    if (top == n - 1) {
        cout << "Stack is full!" << endl;  // Improved message
    } else {
        stack[++top] = value;  // Increment top and add the value
        cout << "The value " << value << " is pushed." << endl;  // Improved formatting
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {  // Corrected the condition to check if the stack is empty
        cout << "Stack is empty!" << endl;
        return -1;  // Return a sentinel value
    } else {
        return stack[top--];  // Return the top element and decrement top
    }
}

// Function to read the top element of the stack
int read_operation() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;  // Improved message
        return -1;  // Indicate that the stack is empty
    } else {
        cout << "The top element is " << stack[top] << endl;
        return stack[top];  // Return the top element
    }
}

int main() {
    // Example usage of the stack
    push(20);
    push(21);
    push(22);
    push(23);
    
    read_operation();  // Display the top element
    
    cout << "Popped: " << pop() << endl;  // Pop the top element and display it
    read_operation();  // Check the new top element after popping
    
    return 0;  // Indicate that the program ended successfully
}
