#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Person 
{
    public :
        string name;
        int age;

        //Person(){} //  이 부분 뭔지 유심히 봐야함 . 
    /*
        Person(string n = "Tom", int a = 23)
     {
        name = n;
        age = a;
     }
        */
       Person (string n, int a): name(n), age(a)
       {
            
       }
       
};
// c++ automatically provide default constructor 
// c++ allows function overlaoding. Same function name with different parameters
// same function name, same parameter : function overriding
// same function name, different paratmeter : function overloading
// from function overridiing, you can make multiple Constructor(same class name with different Parameter)
int main()
{
    //Person* p2 = new Person(); // we got a error ? why ? 
     Person *p1 = new Person("Alice", 21); // 왜 에러가 나는거임?? 
    
   

    return 0;
}

int foo(void){}
int foo(int i){}
int foo(double j) {}

// declare constructor explicitly  or default value 