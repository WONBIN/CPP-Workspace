//Test inline function, lambbda function, and function template 
#include <iostream>
#include <vector>
#include <functional>

using namespace std;


/*
int add(int a, int b)
{
    return a + b;
}*/

#define SQUARE(x) ((x) * (x)) // macro function, not type safe, can cause side effects, not recommended in modern C++
// # means peprocessing before compiliing my source code , please include  

inline int add(int a, int b) // do not make function code : just put it in to main function, so compiler can optimize it.g
{
    return a + b;
}
/*
int add(int a, int b)
{
    return a + b;
}*/



int main()
{
    add(3,5);
    SQUARE(4);
    //[](type parameter name){function body} lambda function 
    //[](type& parameter name){function body}(arguments)
    int a = [](int x, int y){return x + y;}(10,20);
    cout << "Value of a: " << a << endl; // Output: Value of a: 30
    auto addLambda = [](int x, int y){return x + y;}; // lambda function assigned to a variable
    cout << "Result of addLambda(15, 25): " << addLambda(15, 25) << endl; // Output: Result of addLambda(15, 25): 40
    auto i = addLambda(5,10); // auto keyword can 
    cout << "Value of i: " << i << endl; // Output: Value of
    function<int(int, int)> addFunction = [](int x, int y){return x + y;}; // function template and function name can be used as a variable
    cout << "Result of addFunction(20, 30): " << addFunction(20, 30) << endl; // Output: Result of addFunction(20, 30): 50
    //Function template 
    int m = 3;
    int n = 5;

    function<int(void)> addFunc = [m, &n] {return m + n;};
    cout << "Result of addFunc(): " << addFunc() << endl; // Output: Result of addFunc(): 8
    m = 22;
    n = 44;
    cout << "Result of addFunc() after modifying m and n: " << addFunc() << endl; 

    //Nested Lambda function
    int m = [](int x) {return [](int y) {return y*2;} (x) + 3;}(5);
    cout << "Result of nested lambda: " << m << endl; // Output: Result of nested lambda: 10
    return 0;
}