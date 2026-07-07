#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x = 10;
    //capturing by reference 
    auto f = [&x](){
      x+=5;   // Output: Value of x: 10
    };
    x = 20;
    f();
    cout << "Value of x: " << x << endl; // Output: Value of x: 25
    //Basic Lambda funtion to check if a number is even or odd
    auto isEven = [](int num) { return num % 2 == 0; };

    int number = 4;
    if(isEven(number))
    {
        cout << number << " is even." << endl; // Output: 4 is even.
    }
    else
    {
        cout << number << " is odd." << endl;
    }
    //Using Lambda function with STL algorithms
    vector<int> numbers = {1, 2, 3, 4, 5};
    cout << "Even numbers in the vector: ";
    int count = count_if(numbers.begin(), numbers.end(), [](int num){ return num % 2 == 0; }); // algorithm provides function , ansd we use lambda function.
    // 여기서 iterator가 뭐지??
    cout << count << endl; // Output: Even numbers in the vector: 2
    //Using Lambda function to display vector elements with a condition
    for_each(numbers.begin(),numbers.end(),[](int num)
    {
        cout << num << " ";
        if(num % 2 != 0)
        {
            cout << "*";
        }
        cout << endl;
    });
    cout <<endl;
    //capturing by value
    int a = 5;
    auto addA = [a](int x)
    {
        return a+x;
    };
    cout << "Result of addA(10): " << addA(10) << endl; // Output: Result of addA(10): 15
    //capturing by reference and modifying the captured variable
    int b = 10;
    auto addB = [&b](int x)
    {
        b += x;
        return b;
    };
    cout << "Value of b after calling addB: " << b << endl; 
    //Using lambda function to sort a vector in descending order
    vector<int> vec = {5, 2, 9, 1, 3}; // container
    sort(vec.begin(), vec.end(), [](int a, int b){ //return a > b; }); // Sort in descending order
        return a < b; // Sort in ascending order
    });
        //vec.begin() and vec.end() are iterators that point to the beginning and end of the vector, respectively. They are used to specify the range of elements to be sorted. The lambda function [](int a, int b){ return a > b; } is passed as the third argument to the sort function, which defines the sorting criteria (in this case, sorting in descending order).

        cout << "Sorted vector in descending order: ";
    for(int num : vec) // 봄유ㅏ 가번 for loop 로써 int num은 벡터에서 꺼낼 숫자를 담을 임시 바구니이고 :은 ~안에 있는(from) 그리고 vector는 대상이 되는 container임. 
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;

}

