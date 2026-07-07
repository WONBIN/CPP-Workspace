// class Base has an int x Derived class from Base
#include <iostream>
using namespace std;

class Base {
public:
int x = 10;
};

class Derived : public Base {
public:
int x = 20;
};

int main() {
Derived d;
cout << d.x << endl; // This will print 20, as it accesses the x in Derived class
cout << d.Base::x << endl; // This will print 10, as it accesses the x in Base class
return 0;
}