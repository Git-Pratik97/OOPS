#include<iostream>

using namespace std;

class Complex
{
    private:
        int real, imag;

    public:
        Complex(int i= 0, int r = 0)
        {
            real = r;
            imag = i;
        }

        Complex operator + (Complex const &obj)
        {
            Complex res;
            res.real = real + obj.real;
            res.imag = imag + obj.imag;

            return res;
        }

        void display()
        {
            cout << real << " + i" << imag <<endl;
        }
};

int main()
{
    Complex a(2,3);
    Complex b(3,4);
    Complex c = a + b;
    c.display();

    return 0;
}