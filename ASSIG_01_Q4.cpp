#include<iostream>
using namespace std;

class node{
    public:
    int info;
    node* link;
    node(int val){
        info = val;
        link = NULL;
    }
};

void insert(node* &list, int num)
{
    node* temp = list;
    node* n = new node(num);
    if (list == NULL)
    {
        list = n;
        return;
    }
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = n;
}

void display(node* list)
{
    node* temp = list;
    while (temp != NULL)
    {
       cout << temp->info << "-->";
       temp = temp->link;
    }
    cout << "NULL" << endl;
}

node* findNode(node* list, int value)
{
    node* temp = list;
    while (temp != NULL)
    {
        if (temp->info == value)
        {
            return temp;
        }
        temp = temp->link;
    }
    return NULL;
}

int main()
{
    node* list = NULL;
    insert(list, 18);
    insert(list, 32);
    insert(list, 23);
    insert(list, 16);
    insert(list, 43);
    insert(list, 87);
    insert(list, 25);
    insert(list, 44);
    
    display(list);

    node* A = findNode(list, 32);
    node* B = findNode(list, 87);

    // a. Make A point to the node containing info 23.
    A = findNode(list, 23);

    // b. Make list point to the node containing 16.
    list = findNode(list, 16);

    // c. Make B point to the last node in the list.
    while (B->link != NULL) {
        B = B->link;
    }

    // d. Make list point to an empty list.
    list = NULL;

    // e. Set the value of the node containing 25 to 35.
    node* node25 = findNode(list, 25);
    if (node25 != NULL) {
        node25->info = 35;
    }

    // f. Create and insert the node with info 10 after the node pointed to by A.
    node* newNode = new node(10);
    newNode->link = A->link;
    A->link = newNode;

    // g. Delete the node with info 23. Also, deallocate the memory occupied by this node.
    node* temp = list;
    node* prev = NULL;
    while (temp != NULL && temp->info != 23) {
        prev = temp;
        temp = temp->link;
    }
    if (temp != NULL) {
        if (prev != NULL) {
            prev->link = temp->link;
        } else {
            list = temp->link;
        }
        delete temp;
    }
     display(list);
    return 0;
}
