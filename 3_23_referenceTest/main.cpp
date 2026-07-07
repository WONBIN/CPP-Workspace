// Reference test
#include <iostream>

using namespace std;

int main()
{
    int x = 5;
    int y = 10;
    
    int& ref = x; // Not physically in the stack 
    ref = y; // This will change the value of x to 10, you can't reinitalize ref .
    cout << "x: " << x << endl;
    cout << "ref: " << ref << endl;
    ref = 20; // modifying ref will modify x
    cout << "After modifying ref: " << x << endl;
    cout << "x addr: " << &x << endl;
    cout << "ref addr: " << &ref << endl;

    int *ptr = &x;
    cout << "ptr: " << ptr << endl;
    cout << "*ptr: " << *ptr << endl;

    //int &ref2; // Error: reference must be initialized

    return 0;
}
// reference를 선언했을 때는 초기화를 무조건 해야함.그(int &Ref라고만하면 무조건 error)리고 한 번 초기화를 하면 그 값을 바꿀 수는 있어도 그 변수의 주소는 절대로 못 바꾼다. 