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

class Car : private Motor
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

int main()
{
    Car myCar;
    myCar.Move();
    //myCar.SwitchIgnition();
    SuperCar mySuperCar;
    mySuperCar.Move();
    return 0;
}
//  private 상속은 motor의 기능을 car 내부에서만 쓸 수 있게 한다 .