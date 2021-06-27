#include<iostream>

using namespace std;

class student
{
    string name;

    public:

    int age;
    bool gender;

    student()
    {
        cout << "Default Constructor_" <<endl;
    }

    student(string s, int a, bool g) //Construnctor (Parameterised)
    {
        cout << "Parameterised Constructor_" <<endl;
        name = s;
        age = a;
        gender = g;
    }

    student(student &a)
    {
        cout << "Copy Constructor_" <<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    void set_name(string s)
    {
        name = s;
    }

    void get_name()
    {
        cout << name <<endl;
    }

    bool operator == (student(&a))
    {
        if(name==a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }

    void print_info()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age <<endl;
        cout << "Gender: " << gender <<endl;
    }

    ~student()
    {
        cout << "Destructor_" <<endl;
    }
};

int main()
{
    student a("Pratik",21, 0);
    a.print_info();

    student b("Rahul", 25, 0);
    student c = a;

    if (c==b)
    {
        cout << "Same" << endl;
    }
    else{
        cout << "Not Same" <<endl;
    }

    return 0;
}