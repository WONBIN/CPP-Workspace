//Union Test
//union SimpleUnion int float char

// struct ComplexType enum Datatype {INT, FLOAT, CHAR} dataType;
// struct has a union value {int float char} value;
#include <iostream>
#include <string>

using namespace std;

union SimpleUnion
{
    int intValue;
    float floatValue;
    char charValue;
};

struct ComplexType 
{
    enum DataType {INT, FLOAT, CHAR} dataType;
    union Value
    {
        int intValue;
        float floatValue;
        char charValue;

        Value() {} // Default constructor for the union 
        ~Value() {} // Destructor for the union
    } value;

};

// memory space, default constructor, copy constructor, etc. you should trace it.! 
// 계속 강조하네 . class는 그냥 template인데 즉 그럼 memory를 소유하고 있지 않은 건데
// static은 allocated by compiler라서 memory를 가지고 있어야함 .
// Operator + () 할 때 왜 operand 가 하나 밖에 없지?  아하 this가 존재하는구ㅏㄴ 

void DisplayComplexType(const ComplexType& complex)
{
    switch(complex.dataType)
    {
        case ComplexType::INT:
            cout << "Int Value: " << complex.value.intValue << endl;
            break;    // INT BELONGS TO COMPLEX TYPE    
        case ComplexType::FLOAT:
            cout << "Float Value: " << complex.value.floatValue << endl;
            break;
        case ComplexType::CHAR:
            cout << "Char Value: " << complex.value.charValue << endl;
            break;
        }
}

int main()
{
    SimpleUnion simpleUnion;
    simpleUnion.intValue = 42;
    cout << "Int Value: " << simpleUnion.intValue << endl;       
    simpleUnion.floatValue = 3.14f;
    cout << "Float Value: " << simpleUnion.floatValue << endl;  
    simpleUnion.charValue = 'A';
    cout << "Char Value: " << simpleUnion.charValue << endl;    

return 0;
// union is not type sensitive variant 
}