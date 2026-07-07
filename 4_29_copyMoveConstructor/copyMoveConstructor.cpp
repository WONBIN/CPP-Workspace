// Create SimpleCat no member variable
//Default Constructor, Copy Constructor, Destructor 

#include <iostream>

using namespace std;

class SimpleCat
{
    public:
        SimpleCat();
        SimpleCat(const SimpleCat&);
        ~SimpleCat();
};

SimpleCat::SimpleCat()
{
    cout << "Default Constructor" << endl;
}

SimpleCat::SimpleCat(const SimpleCat& obj)
{
    cout << "Copy Constructor" << endl;
}

SimpleCat::~SimpleCat()
{
    cout << "Destructor" << endl;
}

SimpleCat FunctionOne(SimpleCat cat)
{
    cout << "Function One Called" << endl;
    return cat; 
}
SimpleCat FunctionTwo(SimpleCat* cat)
{
    cout << "Function Two Called" << endl;
    return *cat; // This will not call the Copy constructor
}

int main()
{
    SimpleCat Frisky;
    //FunctionOne(Frisky);
    SimpleCat Fluffy = FunctionOne(Frisky);
    FunctionTwo(&Frisky);

    return 0;
}

// copy cosntructor를 지워도 shallow copy (defulat option)가 생성되긴함. 근데 티는 안남. 
// 하나는 function parameter요, 하나는 return cat대신임 . 