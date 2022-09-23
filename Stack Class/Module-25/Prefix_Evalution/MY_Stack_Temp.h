#include<bits/stdc++.h>
using namespace std;

template <typename N>class Node
{
public:

    N data;
    Node* prev;
    Node* next;

    Node(N val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

template <typename S> class Stack
{
    Node <S> *head ;
    Node <S> *top;
    int Count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }

    void push(S n)
    {

        Node <S> *nn = new Node <S> (n);
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

    S pop()
    {
        Node <S> *delNode = top;
        S chk = delNode->data;
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

        return chk;
    }

    void stack_size()
    {
        cout<< "stack size : " <<Count<<endl;
    }
    S top_Value()
    {
        if(top==NULL)
        {
            cout<< "Top Value : NULL"<<endl;
            
        }
        else{
       // cout<< "Top Value : "<<top->data<<endl;
           return top->data ;
        }
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
        Node<S> *temp = head;
        if(head==NULL)
        {
            cout<< "\tStack Underflow\n"<<endl;
        }
        while(temp!=NULL)
        {
            cout<< temp->data << " , ";
            temp=temp->next;
        }
        cout<< endl;
    }
};
