// const reference Test Sample code
#include <iostream>

using namespace std;

int main()
{
    int Original =  30; // non-const variable
    const int& ref = Original; // ref is a const reference to Original. 
    cout << "Original: " << Original << endl;
    cout << "ref: " << ref << endl;
    //ref = 40; // Error: cannot modify a const reference
    Original = 40; // This is allowed: modifying the original variable
    cout << "After modifying Original: " << Original << endl;
    cout << "ref after modifying Original: " << ref << endl; // ref reflects the change in Original
    //int &ref2 = ref;
    int &ref2 = const_cast<int&>(ref); // This is not recommended, but it allows you to modify the value through ref2
    const int &ref3 = ref; // ref3 is a const reference to Original, this is allowed because ref is already a const reference.
    return 0;
}
// double reference는 되는지
//  일반 reference는 reinitalized 될 수 없다. 근데 값은 언제 든지 modify할 수 있다. 만약 const reference라면, reference도 modify 할 수 없다. 