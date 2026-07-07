// Private Inheritance Test
// Motor has 3 functions SwitchIgnition, PumpFuel, FireCyclinders
// Car has Move() function
#include <iostream>
using namespace std;

class Motor
{
    public:
        void SwitchIgnition()
        {
            cout << "Ignition switched on" << endl;
        }
        void PumpFuel()
        {
            cout << "Fuel Pumped" << endl;
        }
        void FireCyclinders()
        {
            cout << "Cyclinders Fired" << endl;
        }   
};

class Car : protected Motor
{
    public:
        void Move()
        {
            SwitchIgnition();
            PumpFuel();
            FireCyclinders();
            cout << "Car is moving" << endl;
        }
};
class SuperCar : protected Car{
    public:
        void SuperMove()
        {
            SwitchIgnition();
            PumpFuel();
            FireCyclinders();
            FireCyclinders();
            FireCyclinders();
            cout << "SuperCar is moving" << endl;
        }
};

int main()
{
    SuperCar myCar;
    myCar.SuperMove();
    //myCar.SwitchIgnition();
    return 0;
}
