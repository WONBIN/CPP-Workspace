// local and global static vasrible test using some functions
#include <stdio.h>
static int globalCount = 0; // global static variable
void func1()
{
    static int count = 0;
    count++;
    printf("func1 called %d times\n", count);
}
void func2()
{
    static int count = 0; // Local static variable 
    count++;
    globalCount++; // Accessing global static variable
    printf("func2 count %d\n", count);
    
}
int main()
{
    func1(); // Output: func1 called 1 times
    func1(); // Output: func1 called 2 times
    func2(); // Output: func2 count 1
    func2(); // Output: func2 count 2
    printf("Global count: %d\n", globalCount++); // Output: Global count: 2
    printf("Global count: %d\n", globalCount); // Output: Global count: 3
    return 0;
}
// keep in mind : implicit type conversion and explicit type conversion 
// static과 global의 차이점 : static은 scope 안에서 함수가 끝나도 값이 유지되지만, 외부의 다른 함수가 이 값을 건드릴 수는 없다. 
//static함수는 초기화가 딱 한 번 된다는게, 일반 local변수는 함수가 매번 call될 때 마다 매번 값이 initalization했을 때 값으로 초기화가 되는데, static은 제일 처음 call 할 때만 되고 그 이후로 여러 번 call 됐을떄도
//그 갱신된 값을 유지 중 . 