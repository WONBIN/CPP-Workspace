// function object test.cpp : THis file contains the 'main' function.Preogram execution...
#include <iostream>
using namespace std;

//A unary function
template<typename T>

void display(T value)
{

}
//Struct to be used as a function object(functor)
struct MultiplyByTwo
{
    void operator()(int& )
    
};
int main()
{
    //Using a function pointer to call a unary function
    void (*funcPtr)(int) = display;
    funcPtr(5);
    cout << endl;

    int arr[] = {1,2,3,4,5};
    MultiplyByTwo multiply; // create an instance of the functor
    for(int& value : arr)
    {
        multiply(value);
    }
    for(const int& value : arr)
    {
        cout << value << " ";
    }
    //1. function object, 2.function pointer

}