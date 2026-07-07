// STL dequeue example
#include <iostream>
#include <deque>

using namespace std;

int main()
{
 deque<int> myDeque;
 myDeque.push_back(5);
 myDeque.push_back(2);
 myDeque.push_front(9);
 myDeque.push_front(1);
 

 cout << "Deque: ";
 for (int num : myDeque)
 {
    cout << num << " ";
 }
 cout << endl;

 return 0;
}
