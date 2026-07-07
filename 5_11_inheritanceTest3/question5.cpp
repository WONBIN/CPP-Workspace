//No virtual and Static Binding
#include <iostream>
using namespace std;

class Base 
{
     public:
        virtual ~Base() 
        {
            cout << "Base destructor called" << endl;
        }
};
class Derived : public Base 
{
    public: 
        ~Derived()
       {
        cout << "Derived destructor called" << endl;
       }
};

int main()
{
   Base * basePtr = new Derived();
   delete basePtr; // This will only call Base destructor because Base's destructor is not virtual, and it will not call Derived destructor, which can lead to resource leaks if Derived has allocated resources that need to be released in its destructor.
    
    return 0;
}
// Destructor를 호출했을 때 baseptr의 type이 base이기 떄문에 ,base destructor가 호출됨
//만약 virtual이 생기면, basePtr이 Derived 객체를 가리키고 있기 때문에, delete basePtr;를 호출하면 Derived의 destructor가 먼저 호출되고, 그 다음에 Base의 destructor가 호출됨. 이렇게 하면 Derived에서 할당한 자원을 제대로 해제할 수 있어서 메모리 누수를 방지할 수 있음.
// virtual이 없으면, delete basePtr;를 호출하면 Base의 destructor만 호출되고 끝남