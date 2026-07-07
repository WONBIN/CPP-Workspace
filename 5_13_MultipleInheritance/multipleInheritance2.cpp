#include <iostream>
using namespace std;


class A
{
    int a;
};
class B
{
    int b;
};
class C : public A, public B
{
    int c;
};

int main()
{
    // A::a가 100번지, B::b가 104번지 , C::c가 108번지에 있다고 했을 떄
    C objC; 
    A* aPtr = &objC; // aPtr은 100번지를 향함
    B* bPtr = &objC; // bPtr은 104번지를 향함 
    return 0;
}
