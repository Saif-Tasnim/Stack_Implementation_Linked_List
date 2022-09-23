#include<bits/stdc++.h>
#include "MY_Stack_Temp.h"
using namespace std;
int option();

int main()
{
    Stack <string> st;
    int ch = option();
    while(ch!=0)
    {
        if(ch==1)
        {
            string  n;
            cout<< "Enter Your Value : ";
            cin>> n;
            st.push(n);
        }
        else if(ch==2)
        {
            st.pop();
        }
        else if(ch==3)
        {
            st.stack_size();
        }
        else if(ch==4)
        {
            st.top_Value();
        }
        else if(ch==5)
        {
            st.empty_stack();

        }
        else if(ch==6)
        {
            st.display();
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
