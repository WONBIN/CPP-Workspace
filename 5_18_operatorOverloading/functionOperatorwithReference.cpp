//function operator with reference
#include <iostream>

using namespace std;

class Incrementer
{
    public:
        int counter;
        void operator()(int& value)
        {
            value++; // increment the value by 1
            counter++; // increment the counter to keep track of how many times the operator
        }
};

int main()
{
    Incrementer increment; // Create an instance of the incrementer class
    increment.counter = 0; // initialize the counter
    int number = 5; // initialize a number
    increment(number); // Use the functino call operator to increment  the number
    cout << "The incremented value is " << number << endl; // output the result
    cout << "The operator was called " << increment.counter << " times" << endl;
    return 0;

}