#include <bits/stdc++.h>
#include "MY_Stack_Temp.h"
using namespace std;

/// prefix evalution
int prefixEvalution(string s)
{
    Stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }

        else
        {
            int a = st.pop();
            int b = st.pop();
            cout << "Operator : " << s[i] << endl;
            if (s[i] == '+')
            {
                st.push(a + b);
                cout << "Operation Value : " << st.top_Value() << "(By Adding)" << endl;
            }
            else if (s[i] == '-')
            {
                st.push(a - b);
                cout << "Operation Value : " << st.top_Value()<< "(By Subtraction)" << endl;
            }
            else if (s[i] == '*')
            {
                st.push(a * b);
                cout << "Operation Value : " << st.top_Value() <<"(By Multiplication)" << endl;
            }
            else if (s[i] == '/')
            {
                st.push(a / b);
                cout << "Operation Value : " << st.top_Value()<< "(By Divission)"  << endl;
            }
            else if (s[i] == '^')
            {
                st.push(pow(a, b));
                cout << "Operation Value : " << st.top_Value()<< "(By Power)"  << endl;
            }
        }
    }

    return st.top_Value();
}

int precedenceCalc(char a)
{
    if (a == '^')
    {
        return 3;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
        return -1;
}

string infixToPrefix(string s)
{
    Stack <char> st;

    /// step - 1 : reverse string s

    reverse(s.begin(), s.end());

    cout<< " 1st Reverse : "<< s<< endl<<endl;

    /// step - 2 : going throw 4 options

    string res; /// store new string
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        { /// if get any value add in res
            res += s[i];
        }

        else if (s[i] == ')')
        { /// if get closing parenthesis push in stack
            st.push(s[i]);
        }

        else if (s[i] == '(')
        { /// if opening parenthesis has come, add top value in res untill close parenthesis found
            while (!st.empty_stack() && st.top_Value() != ')')
            {
                res += st.pop();
            }

            if (st.top_Value() == ')')
            {
                st.pop();
            }
        }

        else /// stack push pop using precendence value
        {
            while (!st.empty_stack() && precedenceCalc(st.top_Value()) >= precedenceCalc(s[i]))
            {
                res += st.pop();
            }
            st.push(s[i]);
        }
    }

    /// step - 3 : pop the string s untill it became empty

    while (!st.empty_stack())
    {
        res += st.pop();
    }

    /// step - 4 : again reverse the string & return into main

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    // -+7*43+20
    // int a = prefixEvalution("-+7*45+20");
    // cout << " Final Answer Is : " << a << endl
    //      << endl;

    // //  +*423
    // a = prefixEvalution("+*423");
    // cout << " Final Answer Is : " << a << endl
    //      << endl;

    string m = "(7+(4*5))-(2+0)";
    string pre = infixToPrefix(m);

    cout << "Prefix String : " << pre << endl
         << endl;

    int f = prefixEvalution(pre);
    cout << "Final Answer is : " << f << endl
         << endl;

    return 0;
}