#include<iostream>

using namespace std;

class base
{
    public:
        virtual void print()
        {
            cout << "This is base's print function." <<endl;
        }
        void display()
        {
            cout << "This is base's display function." <<endl;
        }
};

class derived : public base
{
    public:
        void print()
        {
            cout << "This is derived print function." <<endl;
        }
        void display()
        {
            cout << "This is derived display function." <<endl;
        }
};

int main()
{
    base *baseptr;
    derived d;

    baseptr = &d;

    baseptr -> print();
    baseptr -> display();

    return 0;
}