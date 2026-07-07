#include <iostream>
#include <string>

using namespace std;

int main()
{
    //c++17 feature if statement with initalizer
    if(int x=10; x>5)
    {
        cout << "C++ is successfully configured" << endl;
    
    }
return 0;
}
//constexpr, constexpr function, constexpr class, constexpr if statement 다 compile time에서 진행 
// #define , const , constexpr 이 세 개의 차이점 gemini한테 물어보기  