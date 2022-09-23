#include<bits/stdc++.h>
using namespace std;
int c = 0;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;

public:
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }

};
//Node* head = top = NULL;
Node* createNode(int data);
int option();
void push(Node*&head, Node*&top);
int pop(Node*&head,Node*&top);
int size_stack();
bool empty_stack(Node*&top);
void display(Node*&head, Node*& top);

int main()
{
    Node* top = NULL ;
    Node* head = NULL;
    int ch = option();
    while(ch!=0)
    {
        if(ch==1)
        {
            push(head,top);
        }
        else if(ch==2)
        {
            int chk = pop(head,top);
            if(chk == -1)
                cout<< "Stack is Underflow\n";
            else
                cout<< chk << " is already popped up\n";
        }
        else if(ch==3)
        {
            if(c<1)
            {
                cout<< "Stack size is : 0" << endl;
            }
            else
            {
                cout<< "Stack size : "<<c<<endl;
            }
        }
        else if(ch==4)
        {
            if(top==NULL)
                cout<< "Top Value = NULL " <<endl;
            else
                cout<< "Top Value = " << top->data<<endl;
        }
        else if(ch==5)
        {
            bool b = empty_stack(top);
            if(b)
            {
                cout<< "\tStack is not empty\n";
            }
            else
            {
                cout<< "\tStack is empty\n";
            }
        }
        else if(ch==6)
        {
            display(head,top);
        }
        else
        {
            cout<< "\tInvalid Choice\n";
        }
        ch = option();
    }
}

int option()
{
    cout<< "1. Push Up\n";
    cout<< "2. Pop Up\n";
    cout<< "3. Size Of Stack\n";
    cout<< "4. Top Value\n";
    cout<< "5. List Empty Or Not ? \n";
    cout<< "6. Display The Stack \n";
    cout<< "0. For Exit Code \n";
    cout<< "\nEnter your operation : ";
    int n;
    cin>> n;
    return n;

}

void push(Node*&head, Node*&top)
{
    int val;
    cout<< "Enter your value : ";
    cin>> val;
    Node* nn = new Node(val);

    if(head==NULL)
    {
        head = top = nn;
        c++;
        return;
    }
    top->next = nn;
    nn->prev=top;
    top = nn;
    c++;
}

int pop(Node*&head,Node*&top)
{
    Node* del_node = top;
    if(top==NULL)
    {
        return -1;
    }
    if(head==top)
    {
        int chk = del_node->data;
        head=top=NULL;
        c--;
        return chk ;
    }
    top = del_node->prev;
    top->next=NULL;
    int chk = del_node->data;
    delete del_node;
    c--;
    return chk;
}

int size_stack()
{
    return c;
}

void display(Node*&head,Node*&top)
{
    if(top==NULL)
    {
        cout<< "\tNULL Found\n";
    }
    else if(head==top)
    {
        cout<< top->data << endl;
    }
    else
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<< temp->data << " , ";
            temp = temp->next;
        }
        cout<< endl;
    }
}

bool empty_stack(Node*&top)
{
    if(top==NULL)
        return false;
    else
        return true;

}

