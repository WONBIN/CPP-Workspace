// Specifier override is used to indicate that a member function is 
//meant to override a virtual function in a base clas
// it helps catch errors at compile time
//if the function deos not actually override any base class ufnction.
//such as due to a typo in the function name or incorrect parameter types

#include <iostream>

using namespace std;

class Fish
{
    public:
    virtual void swim()
    {
        cout << "Fish is swimming." << endl;
    } //pure virtual function making Fish
    virtual void swim() const{
        cout << "Fish is swimming.(const version)" << endl;
    }
};
class Tuna : public Fish
{
public:
    void swim() const override final
    {
        cout << "Tuna is swimming swiftly" << endl;
    }
};

int main()
{
    Tuna tuna;
    tuna.swim();
    tuna.Fish::swim();
    Tuna const myTuna;
    myTuna.Fish::swim();
    return 0;
}


//const는 function overriding으로 안치기 때문에 virtual 써도 소용없고, 
//base class에 function overrloading이 필요