//do not pass Base !!! 
//bad Dynamic Cast

#include <iostream>
using namespace std;

class Base
{
    public:
        virtual ~Base() {}
};

class Derived : public Base
{
    public:
        void derivedFunction()
        {
            cout << "Derived function" << endl;
        }
};

int main()
{
    Base b;
    try
    {
    Derived& d = dynamic_cast<Derived&>(b);
    d.derivedFunction();   
    }catch(const bad_cast& e)
    {
        cout << "Caught bad_cast exception" << e.what() << endl;
    }
        
}