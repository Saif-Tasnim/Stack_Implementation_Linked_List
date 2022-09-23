#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node
{
public:
    N data;
    Node *prev;
    Node *next;

    Node(N val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

template <typename S>
class Stack
{
    Node<S> *head;
    Node<S> *top;
    int Count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }

    void push(S n)
    {

        Node<S> *nn = new Node<S>(n);
        if (head == NULL)
        {
            head = top = nn;
            Count++;
        }
        else
        {
            top->next = nn;
            nn->prev = top;
            top = nn;
            Count++;
        }
    }

    void pop()
    {
        Node<S> *delNode = top;
       
        if (top == NULL)
        {
            cout << "\tStack Underflow\n";
        }
        else if (head == top)
        {
            
            head = top = NULL;
           // cout << chk.first << " | " << chk.second << " is already popped up\n";
            cout<< delNode->data << " is already popped up\n";
            Count--;
            delete delNode;
        }
        else
        {
            top = delNode->prev;
            top->next = NULL;
            cout<< delNode->data << " is already popped up\n";
           // cout << chk.first << " | " << chk.second << " is already popped up\n";
            Count--;
            delete delNode;
        }
    }

    void stack_size()
    {
        cout << "stack size : " << Count << endl;
    }
    void top_Value()
    {

        if (top == NULL)
        {
            cout << "Top Value : NULL" << endl;
            return;
        }
             // chk = top->data;
            //  cout<< chk.first << " | " << chk.second << endl;
            cout<< "Top Value : " << top->data << endl;
    }
    bool empty_stack()
    {
        if (top == NULL)
        {
           // cout << "\tStack is empty\n";
           return true;
        }
        else
        {
           // cout << "\tStack is not empty\n";
            return false;
        }
    }

    void display()
    {
        Node<S> *temp = head;
        if (head == NULL)
        {
            cout << "\tStack Underflow\n"
                 << endl;
        }

        while (temp != NULL)
        {
            cout << temp->data << " , ";
            temp = temp->next;
        }
        cout << endl;
    }
};
