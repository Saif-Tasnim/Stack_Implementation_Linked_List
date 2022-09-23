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
            cout<< "Operator : " << s[i]<<endl;
            if (s[i] == '+')
            {
                st.push(a + b);
                cout<< "Operation Value : " << st.top_Value() << endl;
            }
            else if (s[i] == '-')
            {
                st.push(a - b);
                cout<< "Operation Value : " << st.top_Value() << endl;

            }
            else if (s[i] == '*')
            {
                st.push(a * b);
                cout<< "Operation Value : " << st.top_Value() << endl;

            }
            else if (s[i] == '/')
            {
                st.push(a / b);
                cout<< "Operation Value : " << st.top_Value() << endl;

            }
            else if (s[i] == '^')
            {
                st.push(pow(a, b));
                cout<< "Operation Value : " << st.top_Value() << endl;

            }
        }
    }

    return st.top_Value();
}
int main()
{
    // -+7*43+20
    int a = prefixEvalution("-+7*43+20") ;
    cout << " Final Answer Is : " << a << endl<<endl;

    //  +*423
    a = prefixEvalution("+*423") ;
    cout << " Final Answer Is : " << a << endl<<endl;

    return 0;
}