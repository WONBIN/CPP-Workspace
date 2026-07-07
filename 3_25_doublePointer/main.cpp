// double pointer Test sample code

#include <iostream>

using namespace std;

int main()
{
    int x = 5;
    int *ptr = &x;
    int **ptr2 = &ptr;
    int ***ptr3 = &ptr2;
    int ****ptr4 = &ptr3;
    int *****ptr5 = &ptr4;


    cout << "x =  " << x << endl;
    cout << "ptr = " << *ptr << endl;
    cout << "ptr2 = " << **ptr2 << endl;
    cout << "ptr3 = " << ***ptr3 << endl;
    cout << "ptr4 = " << ****ptr4 << endl;
    cout << "ptr5 = " << *****ptr5 << endl;
    
    //if you wanna save address of single pointer variable, you need double pointer.
    
    //(professor comment) single pointer to single dimension array 

    int arr[3] = {1, 2, 3};
    int *ptrArr = arr; // or &arr[0]

    cout <<"arr[0] = " << arr[0] << endl;
    cout<<"arr[1] = " << arr[1] << endl;
    cout<<"arr[2] = " << arr[2] << endl;
    cout<<"ptrArr = " << *ptrArr << endl;
    cout<<"ptrArr + 1 = " << *(ptrArr + 1) << endl;

    //two-dimensional array with double pointer
    int rows = 2, cols = 3;
    int **arr2D = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        arr2D[i] = new int[cols];
    }    
    // saves the starting address of each rows.  
    return 0;
}   
// we have 2 types of pointer : variable poitner and function pointer.
//in cpp style, we prefer to use reference type rather than pointer type. 
