#include <iostream>

using namespace std;

typedef unsigned short int USHORT;

int& GetInt();

int main()
{
    USHORT* pint = new USHORT;
    int j = 200;
    *pint = 10;
    cout << "*pint: " << *pint << endl;
    delete pint;
    *pint = nullptr; // dangling pointer or Stray Pointer 

    cout << "*pint: " << *pint << endl; 
    
    //int &ref = GetInt();
   // cout << "ref: " << ref << endl;
    return 0;
}

int &GetInt()
{
    int nLocation = 25;
    return nLocation;
}