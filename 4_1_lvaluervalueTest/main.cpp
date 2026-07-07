#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
//vector<int> vec = {1, 2, 3, 4, 5};
//vector<char> str = {'H', 'e', 'l', 'l', 'o'};

using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

template <typename T>
void test(T&)
{
    cout << "This is an lvalue reference test" << endl;

}

template <typename T> 
void test(T&&)
{
    cout << "This is an rvalue reference test. "<< endl;
}// through function overriding 

class A
{
     int x; 
     // 궁금증: public이나 private , protected가 아닌 거 위에 int x 처럼 되어있는 건 암묵적으로 뭘 ㅗ처리하나 
    A(int x)
    {
         this->x = x; // x = x 하면 ambiguosus 하니까 
    }
    void display()
    {
        cout << "Value of x: " << this->x << endl; // this  x is member variable

    }
};

int main()
{
    int z = 10;
    test(z);
    test(20);// automatically t reference t reference (rvalue )
    cout << add(10, 20) << endl;
    cout << add(10.5, 20.5) << endl;
    cout << add(string("Hello, "),string("World!")) << endl;

int arr[5] = {1, 2, 3, 4, 5};
cout << "Original Value: ";
for (int i = 0; i < 5; i++) {
cout << arr[i] << " ";
}
cout << endl;

//arr = 20;
int *ptr = arr; // if you wanna modify lvalue, lvalue should have name space. 
// we can modify 
ptr++; // This is okey 
//arr++; THIS IS RVALUE!! 근데 arr도 starting address를 value로 가지고 있는 거 아닌가? arr = 100 이렇게 돼이잖아 .
// arr 처럼 배열은 메모리상에 연속적으로 할당된 5칸짜리 블록의 시작 지점을 가리키는(여기서부터 배열 시작이야라고 고정된 이정표와 같음) 상수와 같은 주소다 . 
int i = 10; // i is lvalue, 
int &refi = i; // refi points to lvalue. refi is lvalue 
refi++; // No error 
//int &refi2 = 10; -> 수정 가능한 lvalue를 참조하는 ref에게 rvalue(temporary)를 할당 할 수 없다 .
cout << "i after incrementing refi" << i <<endl; // Error : cannot bind a non-const lvalue(refi2) reference to a temporary (rvalue, 여기선 10)
// 만약 refi++ 하면 10++ ??  이거 안되는 이유 / 
int &&refi2 = 10;
cout << "refi2: " << refi2 << endl; // refi2 will hold the value 10
refi2++; // 이건 되는 이유 물어보기 : 이건 rvalue reference이기 때문에 그 값을 수정할 수 있다.
cout << "refi2 after incrementing: " << refi2 << endl;

//int& refi3 = 20; // refi3 is not constant, 20 is constant 
const int& refi3 = 20;
// refi3++; // This is not allowed, as we are modifying the temporary through the const reference
cout << "refi3: " << refi3 << endl; // refi3 will reflect the change made throug
return 0;

// class must save starting address of instance.
}
