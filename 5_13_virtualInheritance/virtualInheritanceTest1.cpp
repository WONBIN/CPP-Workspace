// Fish can Swim() Tuna Carp override Swim() Function
#include <iostream>
using namespace std;

class Fish
{
    public:
      virtual void Swim()
        {
            cout << "Fish is swimming" << endl;
        }
    };
class Tuna : public Fish
{
    public:
        void Swim() override 
        {
            cout << "Tuna is swimming swiftly" << endl;
        }
};
class Carp : public Fish
{
    public:
        void Swim () override 
        {
            cout << "Carp is swimming leisurely" << endl;
        }

};

void MakeFishSwim(Fish& fish)
{
    //calling the Swim() function on the Fish reference will invoke 
    fish.Swim();
}

int main()
{
    Fish* myFish1 = new Tuna();
    Fish* myFish2 = new Carp();
    MakeFishSwim(*myFish1);
    MakeFishSwim(*myFish2);
    
    delete myFish1;
    delete myFish2;

    Tuna myTuna;
    Carp myCarp;
    MakeFishSwim(myTuna);
    MakeFishSwim(myCarp);
    return 0;
}