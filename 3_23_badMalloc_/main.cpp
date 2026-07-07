// Bad malloc example
#include <iostream>

using namespace std;

int main()
{
    try {
    int *pAge = new int[536870912]; // Allocate memory for an array of 5 integers    
    // Do something with age 
    delete [] pAge; // Free the allocated memory
}
catch (bad_alloc)
{
    cout << "Memory allocation failed!" << endl;
    return 1; // Exit with an error code
}
/*
catch (const bad_alloc& e) { // what is bad_alloc& - 
    cout << "Memory allocation failed: " << e.what() << endl;
    return 1; // Exit with an error code
}
*/
// 아래 코드와 위 코드의 차이가 뭐야 
    /*
    if(pAge == nullptr)
    {
        cout << "Memory allocation failed!" << endl;
        return 1; // Exit with an error code
    }
    */
       return 0;
}