#include<bits/stdc++.h>
using namespace std;
int top = -1;
///int arr[10];
int c = 0;
int option();
int push(int arr[]);
int pop(int arr[]);
int size_stack();
bool empty_stack();
void display(int arr[]);

int main()
{
    int n;
    cout<< "Enter your array size: ";
    cin>> n;
    int arr[n];
    int ch = option();
    while(ch!=0)
    {
        if(ch==1)
        {
            if(top>=n-1)
            {
                cout<< "\tStack is Overflow\n";
            }

            else
            {
                top = push(arr);
            }
        }
        else if(ch==2)
        {
            if(top==-1)
            {
                cout<< "\tStack is Underflow\n";
            }
            else
            {
                top = pop(arr);
            }
        }
        else if(ch==3)
        {
            if(size_stack()==0)
            {
                cout<< "Size of the stack is : 0\n";
            }
            else
                cout << "Size of the stack is : " << size_stack()<<endl;
        }
        else if(ch==4)
        {
            if(top==-1)
            {
                cout<< "\tTop is NULL\n";
            }
            else
                cout<< "Top Value = " << arr[top]<<endl;
        }
        else if(ch==5)
        {
            bool b = empty_stack();
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
            display(arr);
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

int push(int arr[])
{
    int val;
    cout<< "Enter your value : ";
    cin>> val;
    top++;
    arr[top] = val;
    c++;
    return top;
}

int pop(int arr[])
{
    cout<< arr[top] << " is already popped\n";
    top--;
    c--;
    return top;
}

int size_stack()
{
    return c;
}

bool empty_stack()
{
    if(top==-1)
    {
        return false;
    }
    return true;
}

void display(int arr[])
{
    if(top==-1)
    {
        cout<< "\tNULL Found\n";
        return;
    }
    for(int i=0; i<=top; i++)
    {
        cout<< arr[i] << " , ";
    }
    cout<< endl;
}
