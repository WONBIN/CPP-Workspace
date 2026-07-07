#include <iostream>

using namespace std;

/*
int * foo()
{
    //int arr[3] = {1, 2, 3};
    //int *ppi = new int(4);
    int i = 10;
    //return arr; // 1. is it ok or not okay    --> answer : never return stack address. (Not okay)  address를 카피해도 return 때메 메모리 공간이 사라져서 소용이 없다 .
    return i; // 2. is it okay ? --> okay (copy) --> 어떤 value를 register에 저장됨 . return 
    // 주소를 copy 하려고 해도 , destroy 가된다 
    // emphasization : never ever return stack address. copy is okay : 그니까 없어지는 stack address를 value로 삼으면 망함 ..    
    //main memory에서 allocation을 하는 건 괜찮은데 , local 함수  안에서 array 생성하고 retrun해버리면 존재하는 memory가 다 사라진다 .
    //return ppi; // this is ok 
    //copy means return value or address to register. and we move this register's value to copy 
}
*/
/*
int  bar(int[] temparr)
{
    temparr[0] = 1;

    return temparr;
}
    
*/
int call(int k)
{
    return k;
}
// 교수님 사고 방식
//1. type을 통해 어디에 메모리가 할당되어있는지 ?(stack인지 heap인지) -> arr 같은 경우 foo
//2. arr은 사라진다 (destroy : Not exist anymore)
int main()
{
    int arr2[3] = {3,4,5};
    //int *ptr = foo();
    //bar(arr2);
    cout << arr2[0] << endl;
    int a = 50;
    call(a);
    cout << call(a) << endl;
    return 0;
}

// pointer array, array pointer 
