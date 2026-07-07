#include <iostream>
using namespace std;

class Fish
{
    public:
        Fish()
        {
            cout << " Fish Constructor called." << endl;
        }
        //If we do not declare the destructor in the TUna class,
        //the compiler will generate a default destructor
        //don't forget to always declare the base class destructor as virtual.
        virtual ~Fish()
        {
            cout << " Fish Destructor called." << endl;
        }

      /*  ~Fish()
        {
            cout << " Fish Destructor called." << endl;
        }
            */
};
class Tuna : public Fish
{
    public:
        Tuna()
        {
            cout << " Tuna Constructor called." << endl;
        }
        ~Tuna()
        {
            cout << " Tuna Destructor called." << endl;
        }
};
void DeleteFishMemory(Fish* fish)
{
    delete fish;
}
int main()
{
    Fish *myFish = new Tuna();
    DeleteFishMemory(myFish);
    cout << "Creating another Fish object." << endl;
    Tuna myDinnerFish;
    return 0;
}