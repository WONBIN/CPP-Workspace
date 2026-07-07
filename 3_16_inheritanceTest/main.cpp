#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Animal
{
    public :
    void eat()
    {
        cout << "Eating..." << endl;
    };
};
// : means inheritance 
class Dog : public Animal{
    public :
    void bark()
    {
        cout << "Barking..." << endl;
    };
    void eat()
    {
        cout << "Dog is eating..." << endl;
    } // your own method : override
};

int main()
{
  Dog dog;
  dog.eat(); //Inherited from Animal 
  dog.bark(); //Dog's own method

  int num1 = 10;
  string str; 
  stringstream ss;
    ss << num1; // convert int to string
    ss >> str; // convert stringstream to string
    cout << str << str << endl; // display 

    //pointer practice
    int *ptr = &num1;
    cout << "Address of num1 : " << ptr << endl; // display address of num1
    cout << "Address of num1 : " << &num1 << endl;
    cout << "Address of ptr : " << &ptr << endl;
    cout << "Value of num1 : " << *ptr << endl;

    int num2 = 20;
    ptr = &num2; // point to num2
    cout << "Value of ptr : " << ptr << endl; // display value of num2
    cout << "Value of num2 : " << *ptr << endl; // display value of num2  
    // * is dereference orperator, & is reference operator,   reference = pointer = address 

    cout << "Size of num1 : " << sizeof(num1) << " bytes" << endl; // display size of num1
    cout << "Size of ptr : " << sizeof(ptr) << " bytes" << endl;  // cpu 64bit라서 
    cout << "Size of num2 : " << sizeof(num2) << " bytes" << endl;

    //int a[]; // array declaration without size is not allowed in C++
    //foo (int a[]) 는 가능 (as a function parameter)    

    int arr[10];
    int *ptrArr = arr; // array name is a pointer to the first element of the array
    
    return 0;
}