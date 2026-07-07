// subscriptor overloading
//for example, we can overlod the subscript operator [] to access elements of a class
//Instance[index] = value
//value = Instancep[index];

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class MyArray
{
    private : 
        int arr[5];
    public:
        MyArray()
        {
            for(int i=0; i<5; i++) arr[i] = 0;
        }
        int &operator[](int index) //& reference
        {
            if (index < 0 || index >= 5)
            {
                throw out_of_range("Index out of range");
            }
            return arr[index]; //교수님이 reference를 썻으니까 it's me 그래서 이건 실질적으로 this-> arr[1] == myArray.arr[1] 임을 강조하시네
}
};

int main()
{
MyArray myArray;
myArray[0] = 10; // same as myArray.arr[0] = 10
myArray[1] = 20; // same as myArray.arr[1] = 20
//operator[](int index) == myArray.operator[](0) = 1 looks like this !! 
cout << "Element at index 0: " << myArray[0] << endl;
cout << "Element at index 1: " << myArray[1] << endl;


}
