#include <iostream>

using namespace std;

class A {
    public:
    int i;
    void funcA() {
        cout << "Function in class A" << endl;
        cout << "value of i: " << i << endl;
    }
    void funcA(int x)
    {
        cout << "Function A with parameter: " << x << endl;
    }
    void setI(int value)
    {
        i = value;
    }
    int getI()
    {
        return i;
    }
};

class B : public A {
    public:
    //using A::funcA; // This line allows us to bring all overloaded versions of funcA from class A into class B's scope, so we can call funcA(int x) from class A without ambiguity.
        int i;
        void funcB() {
            cout << "Function in class B" << endl;
            cout << "value of i: " << i << endl; // We can access i from class A because B inherits from A
        }
        void setI(int value)
    {
        i = value;
    } // hide setI in clas A(member variable과 function이 둘다 hide됨.)
        
        void funcA()
        {
            cout << "Function A in class B" << endl;
        }
            
      void funcA(int x)
      {
        A::funcA(x); // This will call funcA(int x) from class A
      }     
};

int main() 
{
    B mya;
    mya.i = 10;  
    mya.setI(20);
    mya.A::setI(30); // This will set the value of i in class A to 30
    mya.A::funcA(); // This will call funcA() from class A
    mya.funcA(); // Calls funcA() from class A
    mya.funcB(); // Calls funcB() from class B
    mya.funcA(10); // We got error because funcA in class B is hides 
   // how to call funcA in class A?
}
//KEY POINT: When you try to override it its 없애는게 아니라, hiding임. 그러나 resoultion namespace 를 이용해 base class에 접근은 할 수 있따
// 이 작업은 compile time에 이루어짐. everything in the stack is decided by compile time. 
