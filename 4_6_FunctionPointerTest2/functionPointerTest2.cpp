// int& foo(int* p){
//     return *p;
// }

#include <iostream>

using namespace std;

int& foo(int* p){
    return *p;
}

int main()
{
    int x = 10;
    int& ref = foo(&x); 
    //int *ref = &foo(&x); // ref is a poiner to the reference returned by foo. 여기서 &의 의미는 foo가 돌려준 결과물의 메모리 주소를 계산하는 연산자임.
    cout << "value of ref:" << ref << endl;
    //cout << "value of ref:" << *ref << endl;// another technique 
    cout << "value of ref: " << ref << endl; // 10
    ref = 20; // modifying ref will modify x
    cout << "value of ref after modification: " << x << endl; // 20
    cout << "Address of ref: " << &ref << endl;
    cout << "Address of x: " << &x << endl;
    cout << ref << endl;
}

//ref = a = *p
// declare local variable pass address, do something return is pointer but return type is reference. so left value 
// reference type can be matched local variable and pointer variable.  reference type can get pointer variable as a value