#include <iostream>

using namespace std;

int main()
{
   int *pNumbers = new int[5]; // Dynamically allocate on array of 5 integers
   //forget to delete the allocated memory, causing a memory leak

   // delete[] pNumbers; // deallocate memory for the array of integers
   // pNumbers = nullptr; // Set pointer to nullptr to avoid dangling pointer : delete를 하고 나서 pNumbers에 nullptr선언해야함
   pNumbers = new int[10];
   delete[] pNumbers; // Properly delete the allocated memory to prevent memroy leak
   pNumbers[0] = 1; // Accessing pNumbers after deletion causes undefined behavior
   
}