// STL vector example
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> myVector;
    myVector.push_back(5);
    myVector.push_back(2);
    myVector.push_back(9);
    myVector.push_back(1);
    myVector.push_back(3);

    cout << "Original Vector: ";
    for (int num : myVector)
    {
        cout << num << " ";
    }
    cout << endl;

    sort(myVector.begin(), myVector.end());
    cout << "Sorted Vector: ";
    for (int num : myVector)
    {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
