#include <iostream>
#include <variant>

using namespace std;

constexpr int square(int x)
{
    return x * x;
}
/*
int square(int x)
{
    return x * x;
}
*/
int main()
{

    int a = 10;

    constexpr int result = square(5);
    std::cout << "The square of sqaure is " << result << std::endl;
    variant <int,double> v = 10;
    double value = get<0>(v);

    //C++ aggregate initalization with a struct and a union
    struct ComplexType
    {
        int num;
        double pi;
    };

    ComplexType complex = {42,3.14}; // Aggregate Initalization of the struct.
return 0;
}
// 여기의 assembly code를 보면 square function.이 없다
// gcc -S .\ constExpr 을 해보면 square function이 없는 걸 알 수 있다 . 