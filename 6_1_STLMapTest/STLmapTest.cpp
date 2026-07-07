// STL map test
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> myMap; // Create a map to store key-value pairs
    //Insert some key-value pairs into the map
    myMap["apple"] = 5;
    myMap["banana"] = 3;
    myMap["cherry"] = 8;
    //Access values using keys
    cout << "Number of apples: " << myMap["apple"] << endl;
    cout << "Number of bananas: " << myMap["banana"] << endl;
    cout << "Number of cherries: " << myMap["cherry"] << endl;
    //Check if a key exists in the map
    string keyToFind = "banana";
    if(myMap.find(keyToFind) != myMap.end())
    {
        cout << keyToFind << " is in the map." << endl;
    }
    else
    {
        cout << keyToFind << " is not in the map." << endl;
    }
    return 0;
}