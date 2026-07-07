#include <iostream>
using namespace std;

class Animal {
public: // 1. public을 추가하여 자식 클래스가 접근할 수 있게 합니다.
    Animal() {
        cout << "Animal constructor" << endl;
    }
    void eat() {
        cout << "Eating" << endl;
    }
    void sleep() {
        cout << "Sleeping" << endl;
    }
};

// 가상 상속을 사용하여 다이아몬드 문제를 방지합니다.
class Mammal : public virtual Animal {
public:
    Mammal() {
        cout << "Mammal constructor" << endl;
    }
    ~Mammal() {
        cout << "Mammal destructor" << endl;
    }
    void feedMilk() {
        cout << "Feeding milk" << endl; // 동작 확인을 위해 출력 추가
    }
};

class Bird : public virtual Animal {
public:
    Bird() {
        cout << "Bird constructor" << endl;
    }
    void fly() {
        cout << "Flying" << endl;
    }
};

// Platypus는 Mammal과 Bird를 상속받으며, Animal은 하나만 존재하게 됩니다.
class Platypus final : public Mammal, public Bird {
public:
    Platypus() {
        cout << "Platypus constructor" << endl;
    }
    void display() {
        cout << "I am a platypus" << endl;
    }
};

int main() {
    Platypus platypus;
    platypus.display();
    platypus.feedMilk();
    
    // Animal의 메서드도 이제 접근 가능합니다.
    platypus.eat(); 

    return 0;
}