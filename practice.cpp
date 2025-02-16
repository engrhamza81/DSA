#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class stack{
    public:
    Node* top;
    stack()
    {
        top=NULL;
    }
    ~stack(){}
    void push(int x)
    {
        Node *newnode=new Node(x);
        newnode->next=top;
        top=newnode;
        cout<<"Pushed: "<<x<<" to Stack\n";
    }
    int pop()
    {
        if(top==NULL)
        {
            cout<<"Stack is Empty";
            return -1;
        }
        else{
            Node* temp;
            int popedvalue=top->data;
            top=top->next;
            delete temp;
            return popedvalue;
        }
    }
    int peek()
    {
        if (top==NULL)
        {
           cout<<"Stack is Empty\n";
           return -1;
        }
        else return top->data;
        
    }
};

int main()
{
stack s;
s.push(10);
s.push(11);
s.push(12);
s.push(13);
cout<<"Top value is :"<<s.peek()<<endl;
cout<<"The value Poped in stack is :"<<s.pop()<<endl;
cout<<"Top value is After Stack is :"<<s.peek();
return 0;
}