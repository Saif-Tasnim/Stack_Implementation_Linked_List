#include <bits/stdc++.h>
#include "MY_Stack_Temp.h"
using namespace std;

/// prefix evalution
int postfixEvalution(string s)
{
    Stack<int> st;
    for (int i = 0; i <s.length() ; i++)
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

string infixToPostfix(string s)
{
    Stack <char> st;

    /// step - 1 : No reverse string s

   
    /// step - 2 : going throw 4 options

    string res; /// store new string
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        { /// if get any value add in res
            res += s[i];
        }

        else if (s[i] == '(')
        { /// if get closing parenthesis push in stack
            st.push(s[i]);
        }

        else if (s[i] == ')')
        { /// if opening parenthesis has come, add top value in res untill close parenthesis found
            while (!st.empty_stack() && st.top_Value() != '(')
            {
                res += st.pop();
            }

            if (st.top_Value() == '(')
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

    // reverse(res.begin(), res.end());

    return res;
}

int main()
{
    

    string m = "(4*(3+5))-(2+0)";
    string pre = infixToPostfix(m);

    cout << "Postfix String : " << pre << endl
         << endl;

    int f = postfixEvalution(pre);
    cout << "Final Answer is : " << f << endl
         << endl;

    return 0;
}