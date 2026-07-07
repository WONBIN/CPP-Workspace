//function pointer simple code example
// This code demonstrates the use of function pointers in C++. It defines a function `square` that takes two integer references as parameters and calculates the square of the first integer, storing the result in the second integer. The `main` function initializes an integer variable, calls the `square` function using a function pointer, and displays the result.

#include <iostream>

using namespace std;

void Square(int&, int&);
void Cube(int&, int&);
void GetValue(int&, int&);
void PrintValue(int&, int&);

void Square(int&x,int& y)
{
    x = x * x * x;
    y = y * y * y;
}
void Cube(int& x, int& y)
{
    x = x * x;
    y = y * y;
}
void GetValue(int& x, int& y)
{
    cout<<"Get value of x and y:" << endl;
    cout << "value of x: " << x << ", value of y: " << y << endl;
}
void PrintValue(int& x, int& y)
{
    cout << "Print value of x: " << x << ", y: " << y << endl;
}
int main()
{
   int a = 2, b = 3;
    void (*funcPtr)(int&, int&); // Declare a function pointer

    funcPtr = Square; // Point to the Square function
    funcPtr(a, b); // Call Square through the function pointer
    cout << "Square of a: " << a << ", Square of b: " << b << endl; // Output: Square of a: 4, Square of b: 9

    funcPtr = Cube; // Point to the Cube function
    funcPtr(a, b); // Call Cube through the function pointer
    cout << "Cube of a: " << a << ", Cube of b: " << b << endl; // Output: Cube of a: 64, Cube of b: 729

    funcPtr = GetValue; // Point to the GetValue function
    funcPtr(a, b); // Call GetValue through the function pointer
    cout << "Value of a: " << a << ", Value of b: " << b << endl; // Output: Value of a: 64, Value of b: 729

    funcPtr = PrintValue; // Point to the PrintValue function
    funcPtr(a, b); // Call PrintValue through the function pointer

    void (*pFuncArray[4])(int&, int&) = {Square, Cube, GetValue, PrintValue}; // Array of function pointers
    for (int i = 0; i < 4; ++i) {
        pFuncArray[i](a, b); // Call each function through the array of function pointers
    }

    return 0;
}

// void (*funcptr) (int&,int&)
//funcptr = cube : function name saves starting addr of the function  