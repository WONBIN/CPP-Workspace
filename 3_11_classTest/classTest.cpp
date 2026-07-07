#include <iostream>

using namespace std;
//Tom is a person
// A person has a name -> member variable: type
//A person has an age 
//A person can sleep.

class Person
{
    public : 
    string name; //member variable
    int age;
    
    void sleep()
    {
        cout << name <<" is sleeping." << endl;
        return;  // this represents the end of the function in void function.
    }
    void myage()
    {
        cout << name <<" is "<< age <<"years old." << endl;
        return;
    }    
};
int main()
{
    Person Tom;
    Tom.name = "Tom";
    Tom.age = 20;
    Tom.sleep();
    Tom.myage();
    cout << "Hello, World!!" << endl;
     return 0;
}