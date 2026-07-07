#include <iostream>
#include <vector>
#include <variant>

using namespace std;

int main()
{
    if(int x=10; x>5)
    {
        cout << "C++ is successful" << endl;
    }
    std:: variant<int, double, std::string> v;


    v = 10;
    cout << "Integer : " << get<int>(v) << endl;

    v = 3.14;
    cout << "Double : " << get<double>(v) << endl;


     v = "Hello Variant";
    cout << "String : " << get<string>(v) << endl;
   

    return 0;
}