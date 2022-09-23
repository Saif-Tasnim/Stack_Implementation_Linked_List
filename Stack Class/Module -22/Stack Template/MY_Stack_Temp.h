#include<bits/stdc++.h>
using namespace std;

class Node
{
public:

    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class Stack
{
    Node* head ;
    Node* top;
    int Count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }

    void push(int n)
    {

        Node* nn = new Node(n);
        if(head==NULL)
        {
            head= top = nn;
            Count++;
        }
        else
        {
            top->next = nn;
            nn -> prev = top;
            top = nn;
            Count++;
        }

    }

    void pop()
    {
        Node* delNode = top;
        if(top==NULL)
        {
            cout<< "\tStack Underflow\n";
        }
        else if(head==top)
        {
            head = top = NULL;
            cout<< delNode->data << " is already popped up\n";
            Count--;
            delete delNode;
        }
        else
        {
            top = delNode->prev;
            top->next = NULL;
            cout<< delNode->data << " is already popped up\n";
            Count--;
            delete delNode;
        }
    }

    void stack_size()
    {
        cout<< "stack size : " <<Count<<endl;
    }
    void top_Value()
    {
        if(top==NULL)
        {
            cout<< "Top Value : NULL"<<endl;
            return;
        }
        cout<< "Top Value : "<<top->data<<endl;
    }
    void empty_stack()
    {
        if(top == NULL)
        {
            cout<< "\tStack is empty\n";
        }
        else
        {
            cout<< "\tStack is not empty\n";
        }
    }

    void display()
    {
        Node* temp = head;
        if(head==NULL)
        {
            cout<< "\tStack Underflow\n"<<endl;
        }
        while(temp!=NULL)
        {
            cout<< temp->data << " , ";
            temp=temp->next;
        }
    }
};
