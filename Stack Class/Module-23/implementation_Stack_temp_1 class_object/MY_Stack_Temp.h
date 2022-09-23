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

    S pop()
    {
        Node<S> *delNode = top;
        // pair<int, char> chk;
        S chk;
        if (top == NULL)
        {
            cout << "\tStack Underflow\n";
            return chk;
        }
        else if (head == top)
        {
            chk = delNode->data;
            head = top = NULL;
           // cout << chk.first << " | " << chk.second << " is already popped up\n";
            //  cout<< delNode->data << " is already popped up\n";
            Count--;
            delete delNode;
            return chk;
        }
        else
        {
            chk = delNode->data;
            top = delNode->prev;
            top->next = NULL;
            //  cout<< delNode->data << " is already popped up\n";
          //  cout << chk.first << " | " << chk.second << " is already popped up\n";
            Count--;
            delete delNode;
            return chk;
        }
    }

    void stack_size()
    {
        cout << "stack size : " << Count << endl;
      
    }
    S top_Value()
    {
      //  pair<int, char> chk;
         S chk;
        if (top == NULL)
        {
            cout << "Top Value : NULL" << endl;
            return chk;
        }
              chk = top->data;
             // cout<< chk.first << " | " << chk.second << endl;
            //cout<< "Top Value : " << top->data << endl;
            return chk;
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

    // S display()
    // {
    //     Node<S> *temp = head;
    //     S chk;
    //     if (head == NULL)
    //     {
    //         cout << "\tStack Underflow\n"
    //              << endl;
    //              return chk;
    //     }

    //     else
    //     {
    //        // pair<int, char> chk;
    //         chk = temp->data;
    //        // cout << chk.first << " | " << chk.second << endl;
    //         // cout << temp->data << " , ";
     
    //        return chk;
    //     }
    //   //  cout << endl;
    // }
};
