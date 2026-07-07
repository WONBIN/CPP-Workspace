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
        void show() override 
       {
        cout << "Derived class show" << endl;
       }
};

int main()
{
    Derived d;
   Base b = d; 
   b.show(); // outcome : Base class show or derived class show 
   // Base show due to static binding

    return 0;
}
//  