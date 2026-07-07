#include <iostream>

using namespace std;

int main()
{
 int numbers[10] = {0};
 int *p;

 for(int n=0; n<10; n++)
    cout << "Numbers element: [" << n << "] " << numbers[n] << endl;
 cout <<endl;
 
 p = numbers;  *p = 10; // 0번지 value = 10
 p++; *p = 20; // 1번지 value = 20
 p = &numbers[2]; *p = 30; // 2번지 value = 30
 p = numbers + 3; *p = 40; // 3번지 value = 40
 p = numbers; *(p+4) = 50; // 4번지 value = 50

 //Only these *,p,++,() are allowed!!
 cout << *p << endl; // 
 cout << *(++(++p)) << endl; // p 현재 위치 2번지, output : 30  p: 30 
 cout << (*p)++  << endl;  //  p현재 위치 : 2 output : 30, p:31
 cout << *(++p) << endl; //  p현재 위치 : 3번지  output: 40 p: 40
 cout << (*(++p))++ << endl;  //  p현재 위치 :4번지, output은 50 p:51  
 cout << (*(p++)) << endl; //   p현재 위치 : 5번지, output: 51 p:0
 cout << (*p)++ << endl;   //   p현재 위치 : 5번지 , output : 0 p : 1
 cout << *(p++) << endl; // 현 위치 : 6번지 output : 1 p: 0
 cout << (++(++(*p))) << endl; // 현위치 : 6번지 output : 2, P ; 2
 cout << ++(*(++p)) << endl; // 현위치 7번지 output : 1 p : 1
 cout << ++(*(++p))  << endl; // 현위치 주소 : 8번지 output : 1 p : 0
 cout << ++(*(++p)) << endl;
 for(int n=0; n<10; n++)
    cout << "Numbers element:[" << n << "] " << numbers[n] << endl;
 cout <<endl;

    
return 0;
}