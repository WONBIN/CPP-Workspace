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
    {}; // Salt water 
    //만약 Tuna() : Fish()였다면 Fish의 기본 생성자가 호출되고, FreshWaterFish는 초기화된 값이 들어가니까, false로 초기화됨.
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
    {}; // Fresh water {}
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

    return 0;
}