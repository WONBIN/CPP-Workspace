//Abstract Base Classs Test.cpp : This file contains the 'main function
// This code demonstrates the concept of abstract base class in C++

#include <iostream>

using namespace std;

class Fish
{
    public:
        virtual void swim() = 0; //pure virtual function making Fish 
        void Eat()
        {
            cout << "Fish is eating." << endl;
        }
};
class Tuna : public Fish
{
    public:
       
    void swim() override
        {
            cout << "Tuna is swimming swiftly" << endl;
        }
        
};

class Shark : public Fish
{
    public:
    
    void swim() override 
        {
            cout << "Shark is swimming powerfully." << endl;
        }
            
           void Eat()
           {
               cout << "Shark is eating." << endl;
           }
};

void MakeFishSwim(Fish& fish)
{
    fish.swim();
}
int main()
{
    // Fish myFish;
    Tuna myTuna;
    myTuna.Eat();
    myTuna.swim();
    Shark myShark;
    myShark.swim();
    myShark.Eat();
    cout << "Using MakeFishSwim FUNCTION" << endl;
    MakeFishSwim(myTuna);
    MakeFishSwim(myShark);  
    return 0;
}