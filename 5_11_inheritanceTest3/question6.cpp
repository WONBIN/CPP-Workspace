//No virtual and Static Binding
#include <iostream>
using namespace std;

class Base 
{
    public:
        Base()
        {
            show();            
        }
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
    // outcome : Base class show or derived class show
    // d가 아직 생성되지 않았기 때문에 

    return 0;
}
// 왜? : 