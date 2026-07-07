// Class Base Class Derived method show() Override
#include <iostream>
using namespace std;
class Base
{
    public:
    int i;
    int j;
    int k;

        
    virtual void show()
        {
            cout << "Base class show function called." << endl;
        }
        
     /*virtual void show()
    {
        cout << "Base class show function called." << endl;
    }*/
    // virtual 뺴냐 마냐에 따라 sizeof가 맞추기

};

class Derived : public Base
{
    public:
    /*
        void show()
        {
            cout << "Derived class show function called." << endl;
        }
        */
   
    void show() override
    {
        cout << "This is overrided function." << endl;
        cout << "Derived class show function called." << endl; 
    }
    
     /* void show() final
    {
        cout << "Derived class show function called." << endl; 
    }
        */
};
//without override compiler should ovveride as much as possible  
// with override keyword : compiler must override
//만약 override를 안하고 싶으면 , final을 쓰면 됨. 
//override,하고 final을 쓰려면 default class에는 virtual이 있어야함 .

int main()
{
    Base baseObj;
    Derived derivedObj;

    cout << "Calling show() using base class object:" << endl;
    baseObj.show(); // Calls Base class show()
    cout << "Calling show() using derived class object:" << endl;
    derivedObj.show(); // Calls Derived class show()

    // 여기서부터 final exam 출제 할 수도 

    Base *p = new Derived();
    cout << "Calling show() using base class pointer to derived object:" << endl;
    p->show(); // Calls Base class show() because it's not virtual

    cout << sizeof(baseObj) << endl; // 

    return 0;
}