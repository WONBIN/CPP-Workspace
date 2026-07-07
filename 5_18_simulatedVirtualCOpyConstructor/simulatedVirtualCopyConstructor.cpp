//Implement simulated virtual copy constructor named Clone() in the base class
//class Fish, class Tuna, class Carp, Fish *Clone() function
#include <iostream>

using namespace std;

class Fish
{
    //ABC class
    public:
        virtual Fish* Clone() = 0;
        virtual void Swim() = 0;
        virtual ~Fish() {};
};
class Tuna : public Fish
{
    public:
        Fish* Clone() override
        {
            return new Tuna(*this); // create a new Tuna object by 
            //copying the current object
        }
        void Swim() override
        {
            cout << "Tuna is swimming." << endl;
        }
};
class Carp : public Fish
{
    public:
        Fish *Clone() override
        {
            return new Carp(*this);
        }
        void Swim() override
        {
            cout << "Carp is swimming." << endl;
        }
};

int main()
{
Tuna myTuna;
Carp myCarp;

Fish* clonedTuna = myTuna.Clone();
Fish* clonedCarp = myCarp.Clone();

clonedTuna->Swim();
clonedCarp->Swim();

delete clonedTuna;
delete clonedCarp;

Fish* fishArray[2];
fishArray[0] = myTuna.Clone();
fishArray[1] = myCarp.Clone();

Fish* myNewFish[2];
for(int i = 0; i < 2; i++)
{
    myNewFish[i] = fishArray[i]->Clone();
    // Clone each fish in the array and store it in myNewFish
}

return 0;
}
// you wanna copy current instane , 
//1. new Class (*this) -> but this technique supports only shallow copy 
//THIS IS RVO!!(Return Value Optimization)