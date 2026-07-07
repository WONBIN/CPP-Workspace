#include <iostream>
// Nothrow example
using namespace std;

int main()
{
    int *pAge = new (nothrow) int[0x1ffffffff];
    if(pAge == nullptr)
    {
        cout << "Memory allocation Failed!" << endl;
        delete[] pAge; // Free the allocated memory
    }
    else{
  cout <<"[No throw] Memory allocation Succeded!"<<endl;
    }
    
  return 0;
}