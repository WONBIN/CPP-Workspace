// A country has only one president.
// We try to implement a class that does not permit copying...
// Create a Singlneton class
#include <iostream>
using namespace std;

class President
{
    private:
       //Private default Constructor
        President() {};
    // Copy Constructor
    President(const President& p);
    //  Assignment Operator
    President& operator=(const President& p); 
    string name;
     
    public:
    // controlled instantiation
    static President& GetInstance() 
    {
        static President p;
        return p;
    }
    string GetName() 
    {
        return name;
    }
    void SetName(string n) 
    {
        name = n;
    }
};

int main()
{
    /*
  President Duck = President::GetInstance();
  Duck.SetName("Donald Duck");  
 */
President& Duck = President::GetInstance();
  Duck.SetName("Donald Duck");
  //President::GetInstance().SetName("Donald Trump"); // Private이니까 GetInstance()을 통해서만 접근 가능.
  //cout << "The president is: " << President::GetInstance().GetName() << endl
  //President Second; // cannot access constructor
  //President *Third = new President(); // cannot access constructor
  //President Fourth = Duck // cannot access copy constructor   
  //Duck = President::GetInstance(); // cannot access assignment operator
  
  return 0;
}