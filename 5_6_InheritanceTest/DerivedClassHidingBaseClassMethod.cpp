// bool FreshWater::canLiveInFreshWater() const
//Tuna is a fish
//Carp is a fish

#include <iostream>

//1st technique : derived class want to initialize bass class?
using namespace std;

class Fish
{
    protected:
        bool FreshWaterFish;

    public:   
        Fish() {}; // 

        Fish(bool isFreshWaterFish)
        {
            FreshWaterFish = isFreshWaterFish;
        }
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
    /*    
    Tuna()
        {
            FreshWaterFish = false; // Tuna is a saltwater fish
        }
            */
    Tuna() : Fish(false)
    {} // Fresh water 
    void swim() // overriding
    {
        cout << "Tuna is swimming." << endl;
    Fish::swim(); 
    }
     
};

class Carp : public Fish
{
    public:
    /*    
    Carp()
        {
            FreshWaterFish = true; // Carp is a freshwater fish
         }
};
*/
    Carp() : Fish(true) // Fresh water 
    {}
    void swim()
    {
        cout << "Carp is swimming." << endl;
    }
};

int main()
{
    Tuna tuna;
    Carp carp;

    cout << "Tuna: ";
    //tuna.FreshWaterFish = true;
    tuna.swim();

    cout << "Carp: ";
    carp.swim();

     //감으로 하는게 아니라 무조건 메모리 그려서 이해해야한다. 무조건 메모리를 그려야하는 것이다. 인지해라 . 수업 후 복습할 때 메모리를 그려야한다.
     //tuna.Fish::swim(); // call base class method
     carp.Fish::swim(); // call base class method
    return 0;
}