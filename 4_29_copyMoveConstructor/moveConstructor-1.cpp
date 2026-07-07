// class Test has an int* data
// Default Constructor
// Destructor 

#include <iostream>
using namespace std;

class Test
{
    int *data;
    public:

        Test(int val = 0)
        {
            data = new int(val);
            cout << "Default Constructor\n";
            cout  << this << "--> [data addr: " << data << ", val: " << *data << "]" << endl;
        }
        //2.Destructor
        ~Test()
        {
            delete data; // copy 해야하니까 we don't need anymore
            cout << "Destructor\n";
        }
        // 3. Copy Constructor
        Test(const Test& other)
        {
            data = new int(*other.data);
            cout << "Copy Constructor\n";
        }
        //4.Copy Assignment
        //test& 하고 return non pointer를 하던가(but this is very dangerous, do not return sth in the stack)
        // test& 하고 heap 을 써 (아니면 static을 쓰던가 )
        // reference -> allocate memory -> this 로 return 받기 
        Test& operator=(const Test& other)
        {
            if(this != &other)
            {
                delete data; // delete를 먼저 해야하는 이유 :: 같은 곳을 pointing을 할 수 도있으니까 
                data = new int(*other.data);
            }
            cout << "Copy Assignment\n";
            return *this;
        }
        //5.Move Constructor 
        Test(Test&& other) noexcept
        {
            data = other.data; // transfer ownership
            other.data = nullptr; // delete 
            cout << "Move Constructor\n";
}
        //6.Move Assignment
        // other has data , data pointes to the heap 
        // first compare if it's different
        // second delete this's data 
        //three this->data = other.data
        // four return *this 
        Test& operator=(Test&& other) noexcept
        {
            cout << "Move operator=\n";
            if(this != &other)
            {
                delete data;
                data = other.data;
                other.data = nullptr;
            }
            return *this;
        }
        void print()
        {
            if(data)
                cout << *data << endl;
            else
                cout << "null\n";    
        }
};

int main()
{
    Test t1(10); // Default Constructor
 
    cout << "\n---copy---\n";
    Test t2 = t1; // Copy Constructor
    t2.print();

    cout << "\n---move---\n";
    Test t3 = std::move(t1); // Move Constructor
    t1 = Test(0); // This is not good idea 
    t2 = t3; // why this is not move assignment? ans: if you wanna move this , rvalue should be temporary object
    // t2 = t3 -> t3도 lvalue형태잖아 . 그러니까 안되지. 
    t3 = Test(50); // This is move operator. test(50)에 접근하려면 name,space가 필요함(lvalue의 특징이지) 근데 test(50)은 name이 없잖아. 그래서 test(50)이 temporary object.
    // temporary object moves assignment 
    // no move assignment는 걱정할 필요 없잔항. 어차피 compiler가 알아서 해주니까.     
    
}