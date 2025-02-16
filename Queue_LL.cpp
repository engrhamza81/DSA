#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class Queue{
    public:
    Node* rare;
    Node* front;
    Queue()
    {
        rare=NULL;
        front=NULL;
    }
    void enqueue(int X){
    Node* newnode=new Node(X);
    
        if(rare==NULL & front==NULL)
        {
            rare=newnode;
            front=newnode;
        }
        else{
            rare->next=newnode;
            rare=newnode;
        }
    }
    int dequeue()
    {
        Node* temp=front;
        if (front==NULL)
        {
            cout<<"QUEUE IS EMPTY\n";
            return -1;
        }
        else{

            int dequeuevalue=front->data;
            front=front->next;
            
            delete temp;
            return dequeuevalue;
        }
        
    }
    int peek()
    {
        if(front==NULL)
        {
            cout<<"QUEUE IS EMPTY\n";
            return -1;
        }
        else return front->data;
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(18);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    cout<<"Front Value in Queue is :"<<q.peek()<<endl;
    cout<<"The value Dequeue Fron Queue is :"<<q.dequeue()<<endl;
    cout<<"Front Value in Queue is :"<<q.peek()<<endl;
}
