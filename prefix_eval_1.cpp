#include<iostream>
#include<stack>

using namespace std;

int prefix_eval(string s)
{
    stack<int> st;

    for(int i = s.length()-1; i >= 0;i--)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i]-'0');
        }

        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+'/* constant-expression */:
                st.push(op1+op2);/* code */
                break;
            
            case '-'/* constant-expression */:
                st.push(op1-op2);/* code */
                break;
            
            case '*'/* constant-expression */:
                st.push(op1*op2);/* code */
                break;
            
            case '/'/* constant-expression */:
                st.push(op1/op2);/* code */
                break;
            
            case '^'/* constant-expression */:
                st.push(op1^op2);/* code */
                break;
            
            default:
                break;
            }
        }
    }
    return st.top();
}


int main()
{
    cout << prefix_eval("-+7*45+20") << endl;

    return 0;
}