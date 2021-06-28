#include<iostream>

using namespace std;

class overload
{
    public:
        void fun()
        {
            cout << "Function wtih no arguments" << endl;
        }

        void fun (int x)
        {
            cout << "Function with int argument" <<endl;
        }

        void fun (double y)
        {
            cout << "Finction with double as a argument" <<endl;
        }
};

int main()
{
    overload obj;
    obj.fun();
    obj.fun(4);
    obj.fun(4.5);
}