// friend Test function name: DisplayAge(const Human& Person)
#include <iostream>
using namespace std;

class Human
{
    private:
        int age;
    public:
        Human(int a) : age(a) {this->age = a;}
        friend void DisplayAge(const Human& Person); 
};

void DisplayAge(const Human& Person)
{
    cout << "Age: " << Person.age << endl;
}
int main()
{

}