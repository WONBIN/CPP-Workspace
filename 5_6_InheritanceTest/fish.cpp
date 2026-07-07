// bool FreshWater::canLiveInFreshWater() const
//Tuna is a fish
//Carp is a fish

#include <iostream>

using namespace std;

class Fish
{
    protected:
        bool FreshWaterFish;
    
    public:    
        void swim()
        {
            if (FreshWaterFish)
            {
                cout << "This fish can swim in fresh water." << endl;
            }
            else
            {
                cout << "This fish cannot swim in fresh water." << endl;
            }
        
        }
};

class Tuna : public Fish
{
    public:
        Tuna()
        {
            FreshWaterFish = false; // Tuna is a saltwater fish
        }
};

class Carp : public Fish
{
    public:
        Carp()
        {
            FreshWaterFish = true; // Carp is a freshwater fish
         }
};

int main()
{
    Tuna tuna;
    Carp carp;

    cout << "Tuna: ";
    //tuna.FreshWaterFish = true; //derived class에서는 접근가능하지만, main 같은 외부에서는 접근 불가임.
    tuna.swim();

    cout << "Carp: ";
    carp.swim();

    return 0;
}