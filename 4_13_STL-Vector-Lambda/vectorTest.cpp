#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void displayVector(int x)
{
    cout <<"Vector elements: ";
    cout << x << " ";
    cout << endl;
}
//structure to display vector elements as Template and unary function (very important, 교수 강조)
template <typename T>
struct Display
{
    void operator()(T x) const {
        cout << x << " ";
    }
};
// operator()는  이걸 함수처럼 쓰겠다는 선언
//(T x) for_each가 벡터에서 요소를 하나씩 꺼내서 이 x 자리에 넣어줌. 템플릿 T를 썼으니 int, double 무엇이든 다 받아낼 수 있는 범용적인 그릇이 됨
// const라는 건 display 내부의 멤버 변수를 절대로 건드리지 않겠다는 약속임. 
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Vector elements: ";
    
    for_each(vec.begin(), vec.end(), displayVector); // using function pointer : displayVector() 이렇게 안 쓰고 그냥 displayVector만 써도 됨. 
    //왜냐면 for_each가 displayVector를 호출할 때, for_each는 함수의 주소를 기다리고 있는 것임. 근데 함수의 이름만 쓰면 컴파일러는 이를 해당 함수가 시작되는 메모리 주소로 자동으로 바꿔줌. 
    
    // using lambda function
    for_each(vec.begin(),vec.end(), [](int x){cout << x << " ";}); // Lambda function to display vector elements
    cout << endl;
    for_each(vec.begin(), vec.end(), Display<int>()); // Template function to display vector elements
    // int를 다루는(int) Display 설계도로(Display) 지금 당장 객체 하나를 구워서(()) 던져라!"
    /*
    struct Display는 T가 뭔지 모르는 범용 설계도임. 근데 <int>를 붙이는 순간, 
    컴파일러는 내부의 모든 T를 int로 바꾼 정수 전용설계도를 실시간으로 뚝딱 만들어냄. 그리고 괄호까지 붙이면, 객체를 생성한 꼴이 되는 것임.  
    */
   // Instead of auto, use iterator to display vector eleements
   Display<int> display;
   vector<int>::iterator it; // vector supports iterator. this iterator supports name sapce
   for(auto it = vec.begin(); it != vec.end(); ++it)
   {
    cout << *it << " "; // Using an iterator to display vector eleements
    display (*it);
    display. operator()(*it); // display(*it)이랑 display. operator()(*it) 이 둘 다 같은 소리하는거임. 원래는 display(*it)를 쓰지만 , 사실은 이게 display 함수를 호출 하는 것이 아닌 operator라는 
    //특수한 함수를 호출하는 것과 같ㄷ.
   }
   // 이게 넘 기니까 stl에서 for_each(begin,end,function)을 만든걸임
    cout << endl;
    return 0;
}

