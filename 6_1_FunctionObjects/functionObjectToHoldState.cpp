// Use a function object to hold state and use it with STL Algorithms
#include <iostream>

template<typename T>
struct DisplayElementKeepCount
{
    int count;
    DisplayElementKeepCount() : count(0) {}
    void operator()(const T& element)
    {
        std::cout << element << " ";
        ++count;
    }
};
// A structure as a unary preedicate to check if an element is even
struct Iseven
{
    bool operator()(int value) const
    {
        return value % 2 == 0;
    }
};
//A structrue as a binary predicate to compare two integers
struct CompareIntegers
{
bool operator()(int a, int b) const
{
    return a<b; //  Return true if a is less than b
}
};

int main()
{
    int arr[] = {1,2,3,4,5};
    DisplayElementKeepCount<int> display;
    
    for(const int& element : arr)
    {
        display(element);
    }
    std::cout << "\nTotal elements displayed : " << display.count << std::endl;
    return 0;

}