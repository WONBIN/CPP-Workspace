// using constexpr with class Human

#include <iostream>

#include <variant>

#include <string>



using namespace std;    



class Human {

public:

    int age;



    constexpr Human(int tempage) :  age(tempage) {} // Constructor for Human class

    constexpr int getAge() const { return age; } // Constexpr member function to get age

};



int main() {

    constexpr Human person(30); // Creating a constexpr Human object

    cout << "The age of the person is: " << person.getAge() << endl; // Accessing the age using the constexpr member function



    Human anotherPerson(25); // Creating a non-constexpr Human object

    cout << "The age of another person is: " << anotherPerson.getAge() << endl; // Accessing the age using the member function

    return 0;

}   