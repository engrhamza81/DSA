#include<iostream>  // Needed for input/output operations
using namespace std;  // To avoid using 'std::' repeatedly

// Definition of the class 'node'
class node{
    public:
    int data;  // Variable to store data in the node
    node *next;  // Pointer to point to the next node

    // Constructor to initialize the node with a value and set the next pointer to NULL
    node(int val)
    {
        data = val;  // Assign the passed value to the node's data
        next = NULL;  // Initialize the next pointer to NULL
    }
};

// Function to insert a new node at the tail (end) of the linked list
void Insert_At_Tail(node* &head, int a)
{
    node* n = new node(a);  // Create a new node with the given value
    node* temp = head;  // Temporary pointer to traverse the list

    // If the list is empty, the new node becomes the head
    if (head == NULL)
    {
        head = n;  // Point head to the new node
        return;  // Exit the function
    }

    // Traverse the list to find the last node
    while (temp->next != NULL)
    {
        temp = temp->next;  // Move to the next node
    }
    temp->next = n;  // Point the last node's 'next' to the new node
}

// Function to delete a node with a specific value
void todel(node* head, int val)
{
    node* temp = head;  // Temporary pointer to traverse the list

    // Traverse the list until the node before the target node is found
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;  // Move to the next node
    }

    // If the target node is found
    if (temp->next != NULL) {
        node* todelete = temp->next;  // Pointer to the node to be deleted
        temp->next = temp->next->next;  // Unlink the node from the list
        delete todelete;  // Free the memory of the deleted node
    }
}

// Function to delete the head node of the linked list
void deleteatHead(node* &head)
{
    if (head == NULL) return;  // Check if the list is empty

    node* todelete = head;  // Pointer to the head node
    head = head->next;  // Move head to the next node
    delete todelete;  // Free memory of the deleted node
}

// Function to display the contents of the linked list
void display(node* head)
{
    node* temp = head;  // Temporary pointer to traverse the list

    // Traverse and print the data of each node
    while (temp != NULL)
    {
        cout << temp->data << "-->";  // Print the data of the current node
        temp = temp->next;  // Move to the next node
    }
   
    cout << "NULL" << endl;  // End the display with "NULL" to represent end of list
}

// Function to insert a node at a specific position
void atposition(node* &head, int val, int pos)
{
    node* temp = head;  // Temporary pointer to traverse the list

    // Special case: If position is 1, we insert at the head of the list
    if (pos == 1) {
        node* toinsert = new node(val);  // Create new node to insert
        toinsert->next = head;  // Link new node's next to the current head
        head = toinsert;  // Update head to point to the new node
        return;
    }

    pos = pos - 1;  // Adjust position to work with 0-based indexing

    // Traverse the list to find the node before the target position
    while (pos > 1 && temp != NULL) {
        temp = temp->next;
        pos--;  // Move closer to the position
    }

    // If we reached the correct position and temp is not NULL
    if (temp != NULL) {
        node* toinsert = new node(val);  // Create new node with value
        toinsert->next = temp->next;  // Link the new node to the next node
        temp->next = toinsert;  // Link the previous node to the new node
    }
}

// Function to reverse the linked list
node* reverse(node* &head) {
    node* preptr = NULL;  // Initialize the previous pointer as NULL
    node* currentptr = head;  // Initialize current pointer to the head of the list
    node* nextptr;  // Pointer to hold the next node during reversal

    // Iterate through the list
    while (currentptr != NULL) {
        nextptr = currentptr->next;  // Save the next node before breaking the link
        currentptr->next = preptr;  // Reverse the current node's next pointer

        preptr = currentptr;  // Move preptr forward
        currentptr = nextptr;  // Move currentptr forward to the next node
    }

    head = preptr;  // Update head to the new first node (preptr)
    return head;  // Return the new head of the reversed list
}

int main()
{
    node *head = NULL;  // Initialize the head pointer to NULL

    // Insert multiple nodes at the tail of the list
    Insert_At_Tail(head, 1);
    Insert_At_Tail(head, 5);
    Insert_At_Tail(head, 3);
    Insert_At_Tail(head, 2);
    Insert_At_Tail(head, 6);

    // Display the original list
    display(head);

    // Reverse the list
    node* newhead = reverse(head);

    // Display the reversed list
    display(newhead);

    return 0;
}
