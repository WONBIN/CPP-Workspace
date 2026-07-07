// call by value, call by reference, call by pointer
#include <iostream>

using namespace std;

void swapByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapByAddress(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(int& a, int& b) // physically exist , behavior like pointer
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 10;
    int y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapByValue(x, y);
    cout << "After swap by value: x = " << x << ", y = " << y << endl;
    //swapByAddress(&x, &y);
    //cout << "After swap by address: x = " << x << ", y = " << y << endl;
    swapByReference(x, y);
    cout << "After swap by reference: x = " << x << ", y = " << y << endl;
    return 0;
}
// Before you run the class(example) code in your class, it'll be better to predict the output of the code.
// And if it's not what you expected, try to understand why it's different from your expectation.

// x is an alias of x.  x is located in swap by Reference, but x is located in main.  

//directly get the value  or get the address of the value and then get the value through dereferencing.
// reference하고 pointer의 assembly code는 같음. 
//결론: Reference just use call user , behaves very similar to pointer (You don't have to worry about pointer .)

// reference type은 high-level abstraction of pointer type to avoid pointer. 
// reference 는 1step, but pointer 2step. (always using pointer is not good)

// Copy value : call by value 
// Copy address : call by reference-type // call by pointer
 