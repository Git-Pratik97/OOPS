#include<iostream>
using namespace std;

#define n 100;

class stack
{
    int* arr;
    int top;

    public:
    stack()
    {
        arr=new int[n];
        top=-1;
    }

    void push(int x)
    {
        if(top > n-1)
        {
            cout << "Stack overslow" <<endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Nothing to pop out" <<endl;
            return;
        }

        top--;
    }

    int top_ele()
    {
        if (top == -1)
        {
            cout << "Empty Stack" << endl;
            return -1;
        }

        return arr[top];
    }

    bool empty()
    {
        return (top == -1);
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.top_ele() <<endl;

    st.pop();
     cout << st.top_ele() <<endl;
    st.pop();
    st.pop();
    st.pop();

    cout << st.empty() <<endl;

    return 0;
}