#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node (int val)
    {
        next=NULL;
        data=val;
    }
};
void insert_at_tail(node* &head, int a)
{
    node* n=new node(a);
    node* temp=head;
    if(head==NULL)
    {
        head=n;
        return;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}
void insert_at_start(node* &head,int a)
{
    node*n=new node(a);
    node* temp=head;
    n->next=head;
    head=n;
}
void insert_at_position(node*head,int pos,int val)
{
        pos=pos-1;
    node* n=new node(val);
    node* temp=head;
    if(pos==1)
    {
        n->next=head->next;
        head->next=n;
        head=n;
    }
    while (temp!=NULL&&pos>1)
    {
        temp=temp->next;
        pos--;
    }
    n->next=temp->next;
    temp->next=n;
}
void deletion(node* head,int val)
{
    node* temp=head;
    while (temp->next->data!=val&&temp!=NULL)
    {
        temp=temp->next;
    }
    if(temp->next!=NULL){
        node* todelete=temp->next;
        temp->next=temp->next->next;
   delete todelete;
   }
}
void display(node* head)
{
     node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    
}
int main()
{
  node* head=NULL;
  insert_at_tail(head,1);
  insert_at_tail(head,1);
  insert_at_tail(head,1);
  insert_at_tail(head,1);
  insert_at_tail(head,1);
  insert_at_start(head,5);
  display(head);
  insert_at_position(head,1,9);
  deletion(head,9);
  display(head);
return 0;
}