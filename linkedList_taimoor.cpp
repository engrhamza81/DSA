#include<iostream>
using namespace std;

class node {
    node() {
        data=0;
        next=null;
    }
    public:
    int data;
    node* next;
};
class ll {
    node * head;
    public:
    ll() {
        head=NULL;
    }
    //insert at head;
    void insert(int data) {
        node* temp = new node();
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    //iinsert at tail
    void insertAtTail(int data) {
        node* temp=new node();
        temp->data=data;
        temp->next=NULL;
        if(head==NULL) {
            head=temp;
            return;
        }
        node* temp1=head;
        while(temp1->next != NULL) {
            temp1=temp1->next;
        }
        temp1->next=temp;
        return;
    }
    void insertAtPosition(int pos,int data) {
        pos=pos-1;
        node* temp1=head;

        node* temp=new node();
        temp->data=data;
        temp->next=NULL;

        while(pos>0) {
            temp1=temp1->next;
            pos--;
        }
        node* nextPart=temp1->next;
        temp1->next=temp;
        temp->next=nextPart;
        return;
    }
    void deleteFromTail() {
        if(head == NULL) {
            return;
        }
        if(head->next == NULL) {
            node* nodeToDelete=head;
            head=NULL;
            delete(nodeToDelete);
            return;
        }
        node* temp=head;
        while(temp->next->next != NULL) {
            temp=temp->next;
        }
        node* nodeToDelete=temp->next;
        temp->next=NULL;
        delete(nodeToDelete);

    }
    void deleteFromHead() {
        if(head == NULL) {
            return;
        }
        node* temp=head;
        head=head->next;
        delete(temp);
        return;
    }

    void display() {
        node* temp=head;
        while(temp != NULL) {
            cout<<temp->data<<" --> ";
            temp=temp->next;
        } cout<<endl;

    }
};
int main() {

    return 0;
}