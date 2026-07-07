// using Constructors to Convert Type
//implicit and explicit
// one of the most difficult topic in C++
#include <iostream>
using namespace std;
class Human
{
    int age;
    public:
    //explicit Human(int a) : age(a) {} // constructor to convert int to Human  -> 만약 이 줄 코드 주석 처리하면 error 발생
    Human(int a) : age(a) {}
    void displayAge()
    {
        cout << "Age: " << age << endl;
    }
};
void DoSomething(Human h)
{
    h.displayAge();
}
int main()
{
    //Human h = 25;  // Using constructor to converet int to Human
    //h.displayAge();  // Output: Age: 25
    //***implicit*** Conversion using constructor 
    Human h2 = 30; // implicit conversion from int to Human using constructor -> 만약 person class 안에 explicit 키워드가 있으면 , error 발생 
    //Human h2(30) -> 이건 constructor를 이용한 거지. implicit하게 type conversion을 한 게 아님. Human h2 = 30 -> 이게 type conversion한 거지 . 오해 금지 !! 
    h2.displayAge(); // cpp automatically converts int to Human using the constructor, and then calls displayAge() method
    // Human에 age가 있기 때문에 automatically plugs in to the constructor, and then calls displayAge() method
    DoSomething(35);
    return 0;
}