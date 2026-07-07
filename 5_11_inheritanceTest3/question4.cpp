//No virtual and Static Binding
#include <iostream>
using namespace std;

class Base 
{
    public:
        virtual void show()
        {
            cout << "Base class show" << endl;
        }
};
class Derived : public Base 
{
    public: 
       void show(int x) // function overloading
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
// virtual이 있으면 function overloaing을 했을 때, vft에 새로운 index에 show(int x)가 추가되고, virtual이 없으면 function overloading을 했을 때, vft에 새로운 index에 show(int x)가 추가되지 않음. 그래서 virtual이 없으면 base class의 show()가 호출되고, virtual이 있으면 derived class의 show(int x)가 호출됨.
