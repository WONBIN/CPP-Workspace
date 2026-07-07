#include <iostream>
using namespace std;

class Adder
{
    public:
        int operator() (int a, int b)
        {
            return a + b;
        }
};

int main()
{
Adder add;
int result = add(5,3); //add.operator()(5,3) 8이 output이 나오더라도 이건 constant이기 때문에 그냥 8이라는 constant가 
cout << "The sum is: " << result << endl;
//cout << "The sum of 10 and 20 is: " << add(10,20) << endl; //add.operator()(10,20) 30이 output이 나오더라도 이건 constant이기 때문에 그냥 30이라는 constant가

return 0;
}