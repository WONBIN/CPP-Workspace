#include <iostream>

using namespace std;

int main()
{
    // Display main address
    cout << "Address of main: " << (void*)main << endl;
    int (*ptr)() = &main;
    cout << "Address of main: through pointer " << (void*)ptr << endl;
    return 0;
}// cpp 는 mpercent 없어도 주소 가지고 올 수 있음 .