#include <iostream>

using namespace std;

int main()
{
    // Type pointer Name = new Type;
    int *p = new int; // allocate memory for an integer and assign its address to pointer p 
    //pointer p 
    *p = 10; // assign the value 10 to the memrory location pointed to by p 
    cout << "Value: " << *p << endl; 

    int arr[5] = {1, 2, 3, 4, 5}; // declare and initialize an array of integers
    int *ptr = arr;
    cout << "Array: " << endl;
    for(int i=0; i<5; i++)
    {
        
        cout << *ptr << " "; // print the value pointed to by ptr
        cout << " Address: " << ptr << endl; // print the address stored in ptr
        cout << *(ptr+i) << endl;
        cout << ptr[i] << endl; // 이것도 value를 내뿜네 

        //ptr++; // move the pointer to the next element in the array
    }
    
    cout << endl;
    delete[] arr;
  

    int *arr2 = new int[5]; // only represents size 
    for (int i = 0; i < 5; i++)
    {
        arr2[i] = i + 1; // assign values to the array elements
    }

    int temp = 10;
    cout << "Value: " << temp << endl;
    cout << "Value: " << ++temp << endl; // pre-increment operator, increments temp before printing its value
    cout << "Value: " << temp++ << endl; // post-increment operator, prints the current value of temp and then increments it

    int *ptr2 = arr2;
    cout << "Array: ";
    for(int i=0; i<5; i++)
    {
        cout << arr2[i] << " "; // print the array elements 이렇게도 사용 가능
    }
    delete[] arr2;
    delete p;
    cout << endl;

   return 0;
}