//make my own Smart Pointer
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <memory> // include for smart pointers if needed(std::un)

using namespace std;


template <typename T>
class smart_pointer
{
    private:
        T *ptr; // Raw pointer to the resource
    public:
        smart_pointer(T *p = nullptr) : ptr(p) {} //Constructor
        ~smart_pointer() { delete ptr; } //Destructor
     // smart pointer , instance gonna be created in stack and automatically call destructor.then destructor automatically call 1000
        T& operator*() { return *ptr; } // overload dereference operator
        T* operator->() { return ptr; } // overload arrow operator

         };
class Date
{
    private:
        int day;
        int month;
        int year;
        string dateStr;

    public:
        Date(int d, int m, int y) : day(d), month(m), year(y) {}
        
        void Display()
        {
            cout << day << "/" << month << "/" << year << endl;
        }
       
};
int main()
{
    smart_pointer<Date> datePtr(new Date(1,1,2026));
    datePtr->Display();
    return 0;
}

