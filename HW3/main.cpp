//You are asked to design a class that manages a dynamic character buffer. 
#include <iostream>
#include <cstring>

using namespace std;

class Buffer{
    private:
        char *data;
        int size;
    
    public:
        // Constructor
        Buffer(const char* str)
        {
            size = strlen(str) + 1;
            data = new char[size];
            strcpy(data,str);
        }    
        //Copy Constructor(Deep Copy)
        Buffer(const Buffer& other)
        {
            // Implement this part
            size = other.size;
            data = new char[size];
            strcpy(data,other.data);
        }
        //Destructor
        ~Buffer()
        {
            delete[] data;
        }

        //Set Data
        void setData(const char *str)
        {
            // implement this part
            delete[] data; // 삭제하고 
            size = strlen(str) + 1; // size 측정
            data = new char[size]; // 새로운 메모리 할당 
            strcpy(data,str); // copy 
        }
        //Print Data
        void print()
        {
            cout << data << endl;
        }
};

int main()
{
    Buffer b1("Hello");

    //Copy Constructor is called
    Buffer b2 = b1;

    b2.setData("World");

    cout <<"b1: ";
    b1.print();
    cout <<"b2: ";
    b2.print();

    return 0;
}