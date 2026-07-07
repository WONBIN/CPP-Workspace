#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    string dateOfBirth;
    string placeOfBirth;
    int age;

public:
    
    // Default constructor
    Person() {
        name = "Unknown";
        dateOfBirth = "Unknown";
        placeOfBirth = "Unknown";
        age = 0;
    }

    // Constructor
    Person(string n, string dob, string pob, int a) {
        name = n;
        dateOfBirth = dob;
        placeOfBirth = pob;
        age = a;
    }

    // Method to talk
    void talk(string textToTalk) {
        cout << name << " says: " << textToTalk << endl;
    }

    // Method to introduce
    void introduce() {
        cout << "Hello, my name is " << name << "." << endl;
        cout << "I was born on " << dateOfBirth 
             << " in " << placeOfBirth << "." << endl;
        cout << "I am " << age << " years old." << endl;
    }
};

int main() {
    // Create a Person object
    Person p1("Alice", "1995-06-15", "New York", 30); // Stack allocation 

    // Call methods
    p1.introduce();
    p1.talk("Nice to meet you!");

    //Heap allocation
    Person *p2 = new Person("Bob", "1988-12-05", "Los Angeles", 35);
    p2->introduce();

    // Clean up heap memory
    delete p2;

    Person *pp1 = &p1;
    pp1->introduce();


    return 0;
}
//()->가 뒤에 붙는 것은 (e.g:display()) :  나는 ()연산자를 재정의하겠다는 뜻임.(이 자체가 이름이다.) 
// 예를 들어 for_each(vec.begin(),vec.end(),Adder())-> Adder()라는 객체를 함수처럼 실행하기 위한 존재임.