#include <bits/stdc++.h>
#include "MY_Stack_Temp.h"
using namespace std;

void reverse_sentence(string n)
{
    Stack<string> st;
    for (int i = 0; i < n.length(); i++)
    {
        string word = "";
        while (i < n.length() && n[i] != ' ')
        {
            word += n[i];
            i++;
        }

         //cout<< word << endl;
        st.push(word);
    }
    st.display();

    while(!st.empty_stack()){
        st.pop();
    }
          
    
}
int main()
{

string s = "I am Saif Tasnim CHowdhury";
reverse_sentence(s);

return 0;
   
}   


