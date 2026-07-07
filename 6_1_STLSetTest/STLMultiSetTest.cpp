// STL multiset test
#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> myMultiset;
    //Insert some values into the multiset
    myMultiset.insert(5);
    myMultiset.insert(2);
    myMultiset.insert(8);
    myMultiset.insert(1);
    myMultiset.insert(9);
    myMultiset.insert(5);

    cout << "Elements in the multiset: ";
    for(const auto& element : myMultiset)
    {
        cout << element << " ";
    }
    cout << endl;
}        
//primitive typed은 operator overloading이 필요하지 않다 .
// type always come with operator 
