// copyConstructor with a simple class, refrence  and const reference
#include <iostream>

using namespace std;
class SimpleCat
{
    public:
    SimpleCat();
    SimpleCat(SimpleCat&); // Copy Constructor : 다른 객체의 참조명을 받곘다 . 
    ~SimpleCat();
};
// :: name space resolution scope -->  이게 뭐지??
SimpleCat::SimpleCat()
{
    cout << "SimpleCat Constructor called!" << endl;
}
SimpleCat::~SimpleCat()
{
    cout << "SimpleCat Destructor called!" << endl;
}
SimpleCat::SimpleCat(SimpleCat& cat)
{
    cout << "SimpleCat Copy Constructor called!" << endl;
}

SimpleCat copyCat(SimpleCat cat)
{
    cout << "Function called"<< endl;
    return cat; // This will call the copy constructor
}
SimpleCat FunctionOne(SimpleCat cat)
{
    cout << "FunctionOne called" << endl;
    return cat; // This will call the copy constructor ->> 1 for parameter, 1 for return value, 1 for Fluffy 
    // destructor가 여기서 2번 호출 : 1 for parameter , 1 for return value.(교수님 강조 )
}

SimpleCat* FunctionTwo(SimpleCat* cat)
{
    cout << "FunctionTwo called" << endl;
    return cat; // This will not call the copy constructor, because we are returning a pointer, not an object. 메모리 자체를 복사한게 아니라 그냥 주소값만 복사했으니 constructor가 안생긴다는 반증이디ㅏ 
}
int main()
{
    cout <<"Creating Frisky" << endl;
    SimpleCat Frisky; //      
 // 여기서부턴 method가 아니라 normal function 
 cout <<"Calling FunctionOne with Frisky" << endl;
 FunctionOne(Frisky); // This will call the copy constructor for the parameter and for the return value
 SimpleCat Fluffy = FunctionOne(Frisky); // This will call the copy constructor for the parameter and for the return value  
  // Fluffy 에서 한 번 Frisky 에서 한 번 , return 에서 한 번 총 3번의 destructor 호출.
 cout << "Calling FunctionTwo with Frisky" << endl;
  FunctionTwo(&Frisky); // This will not call the copy constructor, because we are passing address.
  //
 return 0; // automatically call the destructor of Frisky 
 // stack, copy
}
// we can pass pointer, referen
+