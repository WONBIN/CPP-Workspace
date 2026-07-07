#include <iostream>

using namespace std;

class SimpleCat 
{
    public :
    SimpleCat() // default constructor
    {
        cout << "SimpleCat constructor called!" << endl; // constructor : automatically called when an instance is created. 
    }
    ~SimpleCat() // destructor
    {
        cout << "SimpleCat destructor called!" << endl;
    }
};

int main()
{
    SimpleCat myCat; // create an instance of SimpleCat, which will call the constructor (step 1)
    // The destructor will be called automatically when myCat goes out off scope at the end of the main() 

    //SimpleCat* mycatPtr = new SimpleCat(); // create an instance of SimpleCat on the heap, which will call the constructor
    // 이렇게 했을 때는 destructor가 자동으로 호출되지 않음, 왜냐하면 바로 return 0이 생김
    //stack은 자동적으로 memory space가 생기지만 heap은 내가 직접 다 해야함.(new, delete)
    //delete mycatPtr; // manually call the destructor to free the memory allocated for mycatPtr (step 2)    
    return 0;
} // 이 bracket이 닫히면 , it means terminated, which means return all resources occupoed by the process to OS .