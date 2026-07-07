#include <iostream>

using namespace std;

class Vehicle
{
    protected:
    string brand;
    int speed;   

    public:
    void setVehicle(string b, int s)
    {
        brand = b;
        speed = s;
    }

    void showVehicle()
    {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
    }
};

class ElectricCar : public Vehicle
{
    private:
    int batteryCapacity;

    public:
    void setBatteryCapacity(int capacity)
    {
        batteryCapacity = capacity;
    }

    void showBattery()
    {
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

int main()
{
    ElectricCar car;

    car.setVehicle("Tesla", 200);
    car.setBatteryCapacity(75);

    car.showVehicle();
    car.showBattery();
}