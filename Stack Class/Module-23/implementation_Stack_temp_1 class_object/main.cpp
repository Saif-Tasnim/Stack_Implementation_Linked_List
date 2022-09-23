#include <bits/stdc++.h>
#include "MY_Stack_Temp.h"
using namespace std;
int globalId = 1000;
class Person
{

    string name;
    int id;
    float salary;

public:
    Person()
    {
        name = "";
        id = -1;
        salary = -1.00;
    }

    Person(string name, float salary)
    {
        this->name = name;
        this->salary = salary;
        id = globalId;
        globalId++;
    }

    void print()
    {
        cout << name << " | " << id << " | " << salary << endl;
    }
};

int option();

int main()
{
    Stack<Person> st;
    int ch = option();
    while (ch != 0)
    {
        if (ch == 1)
        {
            // string name ;
            // float salary;
            // cin>> name>> salary;
            Person a("Saif Tasnim", 200.98);
            Person b("Sabran Chowdhury", 300.78);
            Person c("Tasnim Sakib", 400.00);
            // Person a(name,salary);

            st.push(a);
            st.push(b);
            st.push(c);
        }
        else if (ch == 2)
        {
            Person a;
            a = st.pop();
            a.print();
        }
        else if (ch == 3)
        {
            st.stack_size();
        }
        else if (ch == 4)
        {
            Person a;
            a = st.top_Value();
            a.print();
        }
        else if (ch == 5)
        {
            bool b = st.empty_stack();
            if (b)
                cout << "Stack is not empty\n";
            else
                cout << "Stack is empty\n";
        }
        else if (ch == 6)
        {
          while(!st.empty_stack()){
            Person a;
            a = st.pop();
            a.print();
            }
        }
        else
        {
            cout << "\tInvalid Choice\n";
        }
        ch = option();
    }
}

int option()
{
    cout << "1. Push Up\n";
    cout << "2. Pop Up\n";
    cout << "3. Size Of Stack\n";
    cout << "4. Top Value\n";
    cout << "5. List Empty Or Not ? \n";
    cout << "6. Display The Stack \n";
    cout << "0. For Exit Code \n";
    cout << "\nEnter your operation : ";
    int n;
    cin >> n;
    return n;
}
