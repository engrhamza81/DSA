#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertail(node* &head, int x)
{
    node* n=new node(x);
    node* temp=head;
    if (head==NULL)
    {
       head=n;
       return ;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}
void insert_position(node* &head,int x,int pos)
{
    node* n=new node(x);
    node* temp=head;
    pos=pos-1;
    if(pos==1)
    {
        n->next=head->next;
        head->next=n;
        head=n;
    }
    while(temp!=NULL&&pos>1)
    {
        temp=temp->next;
        pos--;
    }
    n->next=temp->next;
    temp->next=n;
}
void display(node* head)
{
    node* temp=head;
    while (temp->next!=NULL)
    {
       cout<<temp->data<<"-->";
       temp=temp->next;
    }
    cout<<"NULL\n";
};
int main()
{
node* head=NULL;
insertail(head,12);
insertail(head,12);
insertail(head,12);
insertail(head,12);
insertail(head,12);
insert_position(head,44,3);
display(head);

return 0;
}