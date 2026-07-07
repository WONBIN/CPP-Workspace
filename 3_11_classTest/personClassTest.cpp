#include <iostream>

using namespace std;
class Person
{
private:
    string name;
    string age;

    public : 

    void introduce()
    {
        cout << "My name is " << name << " and I am " << age << " years old." << endl;
    }
    void setName(string newName)
    {
        name = newName;
    }
    void setAge(string newAge)
    {
        age = newAge;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
};

int main()
{
    Person tom;
    tom.name = "Tom"

   Person person1;
    person1.name = "Alice";
    person1.age = "25";
    
    Person person2;
    person2.name = "Bob";
    person2.age = "30";

    person1.introduce();
    person2.introduce();


     return 0;
}