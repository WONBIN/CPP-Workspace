#include <iostream>

using namespace std;

int main()
{
const int a = 10;
// a = 20;
const double pi = 3.14159;
// pi = 3.14;

cout << "Value of a: " << a << endl;
cout << "Value of pi: " << pi << endl;

int HoursInDay = 24;
cout << "Hours in a day: " << HoursInDay << endl;
const int* pInteger = &HoursInDay;  //pInteger is a pointer to a constant integer !(Please keep in mind)
// HoursinDay가 constant가 아니기 때문에, 변경 가능 (const int *pInteger = &HoursInDay;)
//*pInteger = 12; // Error: cannot modify the value through a pointer to a constant integer
HoursInDay = 12;
cout << "Hours in a day: " << *pInteger << endl;
cout << "Value pointed to by pInteger: " << *pInteger << endl;
// const int *pi, int *const pi, const int *const pi; // pointer to constant integer, constant pointer to integer, constant pointer to constant integer
int MonthsInYear = 12;
cout << "Months in a year: " << MonthsInYear << endl;
pInteger = &MonthsInYear; // pInteger can point to another integer
//*pInteger = 10; // pinteger라는 걸 통해서 값 자체를 못바꾼다 . 
cout << "Months in a year after change: " << MonthsInYear << endl;
//int *pAnotherInteger = pInteger; // type mismatch lvalue : non-const but rvalue : const 
const int *pAnotherInteger = pInteger; // valid, pAnotherInteger is also a pointer to a constant integer

int DaysInMonth = 30;
cout << "Days in a month: " << DaysInMonth << endl;
//const int *const pDaysInMonth = &DaysInMonth;
int *const pDaysInMonth = &DaysInMonth; // pDaysInMonth is a constant pointer to an integer
//pDaysInMonth = &HoursInDay; // Error: cannot change the address stored in a constant pointer
*pDaysInMonth = 31; // valid, we can change the value at the address
}

// very important for the midterm exam ! ! 
