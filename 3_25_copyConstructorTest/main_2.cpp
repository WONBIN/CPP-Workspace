//copy Constructor Test

#include <iostream>

using namespace std;

class Person{
    public:
        string name;
        int age;

        //Default Constructor Person() : name(""), age(0) {}
        Person() {
            name = "Unknown";
            age = 0;
            cout << "Default Constructor called!" << endl;
        }
        Person(string n, int a) : name(n), age(a) {}
        //Copy Constructor
        Person(const Person& other) : name(other.name), age(other.age) {
            cout << "Copy Constructor called!" << endl;
        }
        void print(int i)
        {
            cout << "i: " << i <<" --->"<<"Name: " << name << ", addr:" << &name << ", Age: " << age << ", addr: " << &age << endl;
        }
     //Destructor
        ~Person() {
            cout << "Destructor called for " << name << endl;
        }
};

int main()
{
Person Tom; // automatically call the default constructor
Tom.name = "Tom";
Tom.age = 25;
Tom.print(1);

Person Jerry  = Tom; // Copy Constructor is called
Jerry.print(2);

return 0; // automatically call the destructor of Tom
}