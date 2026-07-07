#include <iostream>

#include <stdio.h>

using namespace std;


class HW3 {

    static int count;

public:

    HW3() {}

    HW3 & operator=(const HW3& t)

    {

        cout << "Run " << count++ << endl;

        return *this;
    }
    HW3(const HW3& t)
    {
        cout << "Run " << count++ << endl;
    }

};

int HW3::count = 1000;

int main()

{

    HW3 hw1, hw2;

    hw2 = hw1;

    HW3 hw3 = hw1;

    return 0;

}