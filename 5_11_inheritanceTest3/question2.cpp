//No virtual and Static Binding
#include <iostream>
using namespace std;

class Base 
{
    public:
        virtual void show()
        {
            cout << "Base classshow" << endl;
        }
};
class Derived : public Base 
{
    public: 
        void show()
        {
            cout << "Derived class show" << endl;
        }
};

int main()
{
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj; // Base class pointer points to Derived class object
    basePtr->show(); // Calls Base class show() because it's not virtual

    Base* ptr = new Derived();
    ptr->show(); // Calls Base class show() because it's not virtual

    return 0;
}
// virtual을 붙혔냐안붙혔냐의 차이에 대한 코드임
