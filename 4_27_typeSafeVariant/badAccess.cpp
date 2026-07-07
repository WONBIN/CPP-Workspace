#include <iostream>
#include <variant>

int main()
{
    std::variant<int, double> v = 10; // Assign  an integer value to the variant 
    try
    {
        std::cout << std::get<double>(v) << std::endl; // Attempt to access
    }
    catch(const std::bad_variant_access& e) // Catch the bad_variant_access exception
    {
    std::cerr << "Caugth Exception: " << e.what() << std::endl;
    }

    return 0;
}
// c++17 new feature 
// 1. type safe variant
// 2.declare  variable and initalize in if
//3.const expression