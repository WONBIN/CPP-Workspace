#include <iostream>

using namespace std;

// struct function operator

struct Printer
{
    template <typename T>
    void operator()(T value) const
    {
        cout << value << endl;
    }
};

int main()
{
    Printer p;
    p(10);
    p("Hello World!");
    p(3.14);

    if (int x=10; x > 5)
    {
        cout << "x is greater than 5:" << x << endl;
    }
    else
    {
        cout << "x is not greater than 5:" << x << endl;
    }
return 0;
}