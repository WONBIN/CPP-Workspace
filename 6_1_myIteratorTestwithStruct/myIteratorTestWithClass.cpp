// class container, class iterator, and functor example
#include <iostream>
#include <algorithm>

using namespace std;

typedef int elementType;
const int SIZE = 10;
class myIterator
{
    public:
    elementType* ptr;
    myIterator(elementType* p) : ptr(p) {}
    elementType& operator*()
    {
        return *ptr; // ptr을 return할 떄 copy를 하려면 &를 쓴
    }
    myIterator& operator++()
    {
        ++ptr;
        return *this; //this==iterator
    }
    bool operator!=(const myIterator& other) const
    {
        return ptr != other.ptr;
    }
    //boolean operator != 을 가리면 error가 나는 이유 
};

class myContainer
{
    public:
    elementType data[SIZE];
    myIterator begin()
    {
        return myIterator(data);
    }
    myIterator end()
    {
        return myIterator(data + SIZE);
    }
};
myContainer myContainerInstance;

int main()
{
    for(int i=0; i<SIZE; ++i)
    {
        myContainerInstance.data[i] = i+1;
    }
    myIterator it = myContainerInstance.begin();
    while(it != myContainerInstance.end())
    {
        cout << *it << " ";
        ++it;
    }
    int i = 10;
    for(int& element : myContainerInstance)
    {
        element = i * 2;
        i++;
    }
    for(const int& element : myContainerInstance)
    {
        cout << element << " ";
    }
    for_each(myContainerInstance.begin(), myContainerInstance.end(), [](const int& element){cout << element << " ";});
    cout << endl;
    return 0;

}