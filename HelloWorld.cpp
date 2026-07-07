#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Person
{
    public:
        string name;
        int age;
    /*Person(string n, int a)
    {
        name = n;
        age = a;
    } */   
    //Person(){}
    Person(string n, int a) : name(n), age(a)
    {

    }
};

int main()
{
    //Person *p2 = new Person();
   Person *p1 = new Person("Alice",23);
  
 return 0;
}