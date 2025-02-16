#include<iostream>
using namespace std;

class node{
    public:
    int info;
    node* link;
    node(int val){
        info=val;
        link=NULL;
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
    // cout<<"a. "<<list->info<<endl;
    // cout<<"b. "<<A->info<<endl;
    // cout<<"c. "<<B->link->info<<endl;
    // cout<<"d. "<<list->link->link->info<<endl;
    // 
      // Marking the following statements as valid or invalid:
    
    // a. A = B; 
    // Valid. Both A and B are pointers of type `node*`, so this is valid. 
    A = B;

    // b. list->link = A->link;
    // Valid. `list->link` and `A->link` are both pointers of type `node*`, so assigning one to another is valid.
    list->link = A->link;

    // c. list->link->info = 45;
    // Valid. `list->link->info` accesses the `info` of the node that `list->link` points to. You can assign a value to `info`.
    list->link->info = 45;

    // d. *list = B;
    // Invalid. The `*list` is dereferencing a pointer and gives a `node` object, whereas `B` is a pointer. You cannot assign a pointer to an object.
    // Uncommenting this will result in an error: // *list = B; 

    // e. *A = *B;
    // Valid. This assigns the values of the object pointed to by `B` to the object pointed to by `A`. This will copy the `info` and `link` from `B` to `A`.
    *A = *B;

    // f. B = A->link->info;
    // Invalid. `A->link->info` is an integer, but `B` is a pointer of type `node*`. You cannot assign an integer to a pointer.
    // Uncommenting this will result in an error: // B = A->link->info; 

    // g. A->info = B->info;
    // Valid. Both `A->info` and `B->info` are integers, so assigning one to the other is valid.
    A->info = B->info;

    // h. list = B->link->link;
    // Valid. `B->link->link` is a pointer of type `node*`, and `list` is also a pointer of type `node*`, so this assignment is valid.
    list = B->link->link;

    // i. B = B->link->link->link;
    // Valid. `B->link->link->link` is a pointer of type `node*`, and `B` is also of type `node*`. This assignment is valid.
    B = B->link->link->link;

    return 0;
}

 