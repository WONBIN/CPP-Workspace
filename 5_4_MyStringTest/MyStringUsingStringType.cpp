//Implement MyString using string class

#include <iostream>
#include <string>

using namespace std;

class MyString
{
    private:
        string str; // cpp string => (By Default) Copy Constructor is provided..
    public:
      MyString(const char* str)
      {
        this->str = str;
      }
      ~MyString()
      {
        cout << "Destructor called for: " << str << endl;
      }
      int GetLength()
      {
        return str.length();
      }
      const char* GetString()
      {
        return str.c_str();
      }         
};

int main()
{
    string mystr("HelloString");
    cout << mystr << endl;
    MyString sayHello("Hello from String class");
    cout << sayHello.GetString() << endl;
    cout << sayHello.GetLength() << endl;
    return 0;
}
// teaching: using existing cpp string class to implement MyString class. do not use your own char* buffer. cpp string class already has copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor implemented. so we can just use the default ones provided by the compiler. this way we can avoid the double free problem and memory leak problem that we might encounter when using char* buffer. also we can take advantage of the functionalities provided by the cpp string class, such as length() and c_str() methods.