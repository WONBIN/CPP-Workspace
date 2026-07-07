// No virtual and Static Binding
#include <iostream>
using namespace std;

class Base {
public:
virtual void show() {
cout << "Base class show" << endl;
}
};

class Derived : public Base {
public:
void show() override {
cout << "Derived class show" << endl;
}
};

int main() {
Derived d;
Base b = d;
b.show(); // Calls Base class show() due to static binding, even though b is a copy of a Derived object

return 0;
}
