#include <iostream>

using namespace std;

class Myclass
{
    public:
        int value; // This is a memeber variable of Myclass that can hold an integer value
        Myclass(int val) : value(val) {}
        void display()
        {
            cout <<"Value: " << value << endl;
        }
        int getValue() const // Constant 
        {
            int i = 10;
            i++;
            //value++; // This is not allowed
            return value;
        }

};

int main()
{
    const int x = 10;
    cout << "value of X " << x <<endl;
    // x = 20;

    Myclass obj(5);
    obj.display();
    cout << "Value of obj: " << obj.getValue() <<endl;

    return 0;
    // 이거 사진 찍은 거 보고 채워 넣으셈

}