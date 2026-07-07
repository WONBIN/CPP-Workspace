// class Base has an int x Derived class from Base
#include <iostream>
using namespace std;

class Base {
public:
int x = 10;
virtual int getX() {
return x;
}
};

class Derived : public Base {
public:
int x = 20;
int getX() override {
return x;
}
void display() {
cout << "Derived class x: " << x << endl;
cout << "Base class x: " << Base::x << endl;
}
};

int main() {
Base* bPtr = new Derived();
cout << bPtr->x << endl; // This will print 10, as it accesses the x in Base class due to pointer type
cout << bPtr->getX() << endl; // This will print 20, as it calls the overridden getX() in Derived class
cout << static_cast<Derived*>(bPtr)->x << endl; // This will print 20, as it accesses the x in Derived class
cout << static_cast<Derived*>(bPtr)->Base::x << endl; // This will print 10, as it accesses the x in Base class
//bPtr->display(); // This will call the display() function in Derived class, showing both x values
//<static_cast<Derived*>(bPtr)->display(); // This will call the display() function in Derived class, showing both x values
reinterpret_cast<Derived*>(bPtr)->display(); // This will call the display() function in Derived class, showing both x values
return 0;
}