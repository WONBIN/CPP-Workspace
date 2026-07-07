// Implementing MyString Class
#include <iostream>
#include <string> // cpp string => (By Default) Copy Constructor is provided..
#include <cstring> // for strcpy() and strlen()

using namespace std;

class MyString
{
    private:
        char* Buffer;
public:
    MyString(const char* str)
    {
        //Check if str is NULL or not 
        // allocate memory space from Heap -> Know size -> how to know ? -> strlen()
        // Need to save the start address -> store into a member variable (Need to hide-> private)
        if (str == NULL)
        {
            Buffer = NULL;
        }
        else
        {
            Buffer = new char[strlen(str) + 1];
            strcpy(Buffer, str);
        }
        cout << "Constructor called with: " << str << endl;
    }
    MyString(const MyString& str)
    {
        if (str.Buffer == NULL)
        {
            Buffer = NULL;
        }
        else
        {
            Buffer = new char[strlen(str.Buffer) + 1];
            strcpy(Buffer, str.Buffer);
        }
        cout << "Copy Constructor called with: " << str.Buffer << endl;
    }
    /*
    operator= (const Mystring)
    */
    //Move Constructor
    MyString(MyString&& str) noexcept
    {
        Buffer = str.Buffer; // transfer ownership
        str.Buffer = NULL; // prevent double deletion
        cout << "Move Constructor called with: " << Buffer << endl;
    }
    //Move Assignment Operator
    MyString& operator=(MyString&& str) noexcept
    {
        cout << "Move Assignment Operator called with: " << str.Buffer << endl;
        if(str.Buffer == NULL)
        {
            Buffer = NULL;
        }
        else
        {
            if(this != &str) // &str이 other
            {
            delete[] Buffer; // delete current buffer
            Buffer = str.Buffer; // transfer ownership
            str.Buffer = NULL; // prevent double deletion
            }
        }
        return *this;
    }
    //Copy Assignment Operator
    //reference
    //allocate memory
    //return this
    MyString& operator=(const MyString& str)
    {
        cout << "Copy Assignment Operator" << endl;
        if (str.Buffer == NULL)
        {
            Buffer = NULL;
        }
        else
        {
            if(this != &str) // &str이 other
            {
                delete[] Buffer; // delete current buffer
                Buffer = new char[strlen(str.Buffer) + 1];
                strcpy(Buffer, str.Buffer);
            }
        }
        return *this;
    }
    // 만약 Buffer가 string이였다면, copy constructor, copy assignment operator, move constructor, move assignment operator 모두가 compiler가 제공하는 default version으로도 충분히 잘 작동할 수 있었을 것임. 하지만 Buffer가 char*이기 때문에, default version이 shallow copy를 하게 되고, 이로 인해 double free 문제가 발생할 수 있음. 그래서 우리는 deep copy를 하는 copy constructor와 copy assignment operator를 직접 구현해야 했음. 또한 move semantics를 활용하기 위해 move constructor와 move assignment operator도 구현했음.
    //Destructor
    ~MyString()
    {
        cout << "Destructor called for: " << Buffer << endl;
        if(Buffer != NULL)
        {
            delete[] Buffer; // delete [] for array
        }
    }
    int GetLength()
    {
        return strlen(Buffer);
    }
    //member method : opt 1 for printing out string 
    const char* GetString()
    {
        return Buffer;
    }
    //operator overloading : opt 2 for printing out string
    operator const char*()
    {
        return Buffer;
    }
    // We will need to implement the following:
    // Destructor
    // Copy Constructor
    // Copy Assignment Operator
    // Move Constructor
    // Move Assignment Operator      
};

void useMyString(MyString str)
{
    cout <<"UseMyString called" << endl;
    cout << str.GetString() << endl;
    cout << str.GetLength() << endl;
    cout << (const char*)str << endl;
    cout << str << endl; // why return; 이랑 같지?
    //만약 copy constructor가 없으면 shallow copy가 일어나서, str이 소멸될 때 Buffer가 delete 되는데, main에서 sayHello도 같은 Buffer를 참조하기 때문에, sayHello가 소멸될 때 또 delete를 하려고 해서 문제가 생김 (double free) 
    
}

int main()
{

    string mystr("HelloString");
    //cout << mystr << endl;
    MyString sayHello("Hello from String class"); // we need to implement constructor that takes const char* as parameter
    cout << sayHello.GetString() << endl;
    cout << sayHello.GetLength() << endl;
    cout << (const char*)sayHello << endl; // operator overloading for type conversion
    cout << sayHello << endl; // operator overloading for type conversion 바로 const char*랑 똑같음
    useMyString(sayHello);
    cout << sayHello << endl;
    return 0;

}
// code 뜯어볼 때도, 복습할 떄도, memory를 어떻게 관리하고 그리는지에 초점을 맞춰서 보는 것도 나쁘지 않게따 .