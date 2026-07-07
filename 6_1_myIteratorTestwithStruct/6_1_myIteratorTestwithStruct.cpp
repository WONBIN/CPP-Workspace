//Implement a Container of with a custom iterator using a struct to represent contact information
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 10;
template <typename elementType>
class DisplayElement
{
public:
    void operator()(const elementType& element) const
    {
        cout << element << " ";
    }
};

template <typename elementType>
class Container
{
    public:
    elementType data[SIZE];
    struct Iterator
    {
        elementType* ptr;
        Iterator(elementType* p) : ptr(p) {}
        elementType& operator*()
        {
            return *ptr; // ptr을 return할 떄 copy를 하려면 &를 쓴다.(optional하긴하지만, )
        }
        Iterator& operator++()
        {
            ++ptr;
            return *this; //this==iterator
        }
        bool operator!=(const Iterator& other) const
        {
            return ptr != other.ptr;
        }
    };
      Iterator begin()
        {
            return Iterator(data);
        }
        Iterator end()
        {
            return Iterator(data + SIZE);
        }
};
int main()
{
    Container<int> myContainer;
    for (int i=0; i< SIZE; ++i)
    {
        myContainer.data[i] = i+1;
    }
    Container<int>::Iterator it = myContainer.begin();
    while (it != myContainer.end())
    {
        cout << *it << " "; // output the current element
        ++it; // Move to the next element
    }
    int i=10;
    for(int& element : myContainer)
    {
        element = i * 2; // Modify the elements by doubling their values
        i++;
    }
    for(const int& element : myContainer)
    {
        cout << element << " ";
    }
    for_each(myContainer.begin(), myContainer.end(), DisplayElement<int>());
    return 0;
}