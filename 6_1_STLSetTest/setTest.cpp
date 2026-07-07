#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    set<int> mySet;
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(1);
    mySet.insert(9);
    mySet.insert(5); // Duplicate value, will not be added

    cout << "Elements in the set: ";
    for(int element : mySet)
    {
        cout << element << " ";
    }
    cout << endl;
    //Check if a value exists in the set
    int valueToFind = 3;
    if(mySet.find(valueToFind) != mySet.end())
    {
        cout << valueToFind << " is in the set." << endl;
    }


}