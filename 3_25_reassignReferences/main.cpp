//reassiign reference  Test
#include <iostream>

using namespace std;

int main()
{
    int intOne;
    int &ref = intOne;
    intOne = 5;
    cout << "intOne: " << intOne << endl;
    cout << "ref: " << ref << endl;
    cout << "intOne addr: " << &intOne << endl;
    cout << "ref addr: " << &ref << endl;
    int intTwo = 10;
    ref = intTwo; // This will change the value of intOne to 10
    cout << "After assigning intTwo to ref: " << intOne << endl;
    cout << "ref after reassigning intTwo: " << ref << endl;
    cout << "intTwo: " << intTwo << endl;
    cout << "ref addr: " << &ref << endl; // ref still refers to intOne, so the address is the same as intOne
    cout << "intTwo addr: " << &intTwo << endl; // intTwo has its own address
 // do not reassign reference,
    return 0;
}