//copy Constructor Test
#include <iostream>
#include <string>

using namespace std;

class Person{
    public:
        string name;
        int age;
        int *ptr; // pointer member to demonstrate deep copy 
        //Default Constructor Person() : name(""), age(0) {}
        Person() {
            name = "Unknown";
            age = 0;      
            ptr = new int(100); // or 
            //*ptr = 10;
            cout << "Default Constructor called!" << endl;
        }
        
        Person(string n, int a) : name(n), age(a) {
        //Copy Constructor
           ptr = new int(100); // or 
            //*ptr = 10;
        };
        
        Person(const Person& other) : name(other.name), age(other.age) {
        //                         name = other.name --> this->name = other.name 이고 instance addr -> name == other.name
                           // this -> name : starting addr of instance 
             ptr = new int(*other.ptr); // Deep copy means allocate new memory and copy value!!
            
             cout << "Copy Constructor called!" << endl;
        }
        
        void print(int i)
        {
            cout << "i: " << i <<" --->"<<"Name: " << name << ", addr:" << &name << ", Age: " << age << ", addr: " << &age 
            << ", ptr: " << ptr << ", *ptr: " << *ptr << endl;
        }
     //Destructor
        ~Person() {
            cout << "Destructor called for " << name << endl;
          
        }
};

int main()
{
Person Tom; // automatically call the default constructor
Tom.name = "Tom";
Tom.age = 25;
Tom.print(1);

//Person Jerry  = Tom; // Default shallow copy is called : 여기선 constructor가 1번만 호출됨
Person Jerry; // automatically call the default constructor(여기서 호출 1번)
Jerry = Tom; // Assignment operator is called, not copy constructor
Jerry.print(2);
Tom.ptr[0] = 20;
Tom.print(3);
Jerry.print(4);
Tom.name = "Tommy";
Tom.print(5);
Jerry.print(6);
Person Spike = Tom; 
Spike.print(7);
return 0; // automatically call the destructor of Tom
}
// person a , person b : default constructor
// a = b : assign(shallow copy: just copy the pointer value)
// person a = b : copy constructor

// 여기서 ptr은 같은 주소의 값을 가리키게됨.(shallow copy) 그래서 Tom의 ptr을 변경하면 Jerry의 ptr도 변경됨.
// Tom의 name을 변경해도 Jerry의 name은 변경되지 않음. 왜냐하면 different address를 가지고 있기 때문. name은 string class의 멤버이므로, string 클래스의 copy constructor가 호출되어 deep copy가 이루어짐. 
// The only difference is type!! ptr은 primitive type임.primitive type은 shallow copy를 함. primitive type은 class가 아니다 . 
// but in case of string it's class type. Inside of class string, we must have copy constructor. and this copy constructor allocate new memory space.
//Then copy string.
// 그래서 class type을 쓰는게 much better. char s[100]; 이런 건 not recommended, string s; 이게 recommended.  

// 참고로 값 자체를 assign할 때는 shallow인지 deep인지 따지지도 않는다. 