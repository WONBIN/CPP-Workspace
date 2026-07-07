// ============================================================
// 기말고사 대비 연습문제 4 (상속/virtual/추상클래스 + operator overloading + predicate/iterator 종합)
// ============================================================
// 풀이 방법:
//   - [OUTPUT] 문제: 주석에 예상 출력 적어보기
//   - [BLANK]  문제: _____ 채우기 (각 빈칸에 번호 표시)
// 각 문제 블록 주석 해제 후 실행 확인
//
// * 이번 세트는 너가 직접 짚은 약점(virtual destructor 체인, abstract class,
//   private 상속 접근/실행 흐름, 비교연산자 도출, smart pointer)과
//   기존에 헷갈렸던 predicate/iterator 영역을 합쳐서 구성했어.
// ============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


// ============================================================
// 문제 1 [OUTPUT] - virtual destructor 체인 (가장 약하다고 짚은 부분)
// 예상 출력을 순서대로 적어보세요. (생성자/소멸자 호출 순서 포함)
// ============================================================
/*
class Base {
public:
    Base()  { cout << "Base constructed"  << endl; }
    virtual ~Base() { cout << "Base destroyed" << endl; }
};

class Derived : public Base {
public:
    Derived()  { cout << "Derived constructed"  << endl; }
    ~Derived() { cout << "Derived destroyed" << endl; }
};

int main() {
    cout << "--- case 1: 스택 객체, 스코프 끝남 ---" << endl;
    {
        Derived d;
    }   // 1~4. 이 블록에서 일어나는 출력을 순서대로?

    cout << "--- case 2: Base 포인터 + delete (virtual destructor) ---" << endl;
    Base* p = new Derived();
    delete p;   // 5~8. 이 두 줄에서 일어나는 출력을 순서대로?

    return 0;
}
*/


// ============================================================
// 문제 2 [BLANK] - 추상 클래스 (abstract class / pure virtual)
// _____ 를 채워서 의도대로 동작하게 하세요.
// (반대로 외웠다고 한 "abstract class 인스턴스화 가능 여부" 직접 확인하는 문제)
// ============================================================
/*
class Shape {
public:
    virtual double area() = 0;                          // (1) 이 함수를 "순수 가상함수"로 만드는 값
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override { return 3.14 * radius * radius; }   // (2) 부모 함수를 재정의함을 명시하는 키워드
};

int main() {
    Shape* sp = new Circle(2.0);
    cout << sp->area() << endl;     // 1. 출력?

     //Shape s2;                    // (3) 이 줄의 주석을 풀면 어떻게 됨? (컴파일 에러 / 정상) 그리고 그 이유는?

    delete sp;
    return 0;
}

*/

// ============================================================
// 문제 3 [OUTPUT] - private 상속에서 "누가 호출하느냐"에 따른 흐름
// 예상 출력을 적고, 마지막 질문에도 답하세요.
// (접근 제어 vs 실행 흐름을 구분하는 연습 — 너가 가장 헷갈린다고 한 부분)
// ============================================================
/*
class Engine {
public:
    void start() { cout << "Engine started" << endl; }
    void stop()  { cout << "Engine stopped" << endl; }
};

class Car : private Engine {
public:
    void drive() {
        start();                      // Car의 멤버 함수 "내부"에서 호출
        cout << "Car driving" << endl;
        stop();
    }
};

int main() {
    Car c;
    c.drive();          // 1~3. 출력?

    // c.start();       // 4. 이 줄의 주석을 풀면? (컴파일 에러 / 정상) 그 이유는?
                        //    (힌트: drive() 안에서 start()를 호출하는 것과
                        //           main에서 c.start()를 호출하는 것의 차이가 뭘까?)
    return 0;
}


*/
// ============================================================
// 문제 4 [BLANK] - operator< 하나로부터 나머지 비교연산자 도출 (4칸)
// _____ 를 채우세요. (operator<, operator== 만 직접 정의되어 있음)
// ============================================================
/*
class Money {
    int won;
public:
    Money(int w) : won(w) {}
    bool operator<(const Money& o)  const { return won < o.won; }
    bool operator==(const Money& o) const { return won == o.won; }

    bool operator>(const Money& o)  const { return o < *this; }   // (1) "내가 크다" = ?
    bool operator<=(const Money& o) const { return !(o < *this); }   // (2) "크다"의 반대
    bool operator>=(const Money& o) const { return !(won < o.won); }   // (3) "작다"의 반대
    bool operator!=(const Money& o) const { return !(won == o.won); }   // (4) "같다"의 반대
};

int main() {
    Money a(1000), b(2000);
    cout << (a < b)  << endl;   // 1. 출력?
    cout << (a > b)  << endl;   // 2. 출력?
    cout << (a <= b) << endl;   // 3. 출력?
    cout << (a >= b) << endl;   // 4. 출력?
    cout << (a != b) << endl;   // 5. 출력?
    return 0;
}
*/


// ============================================================
// 문제 5 [OUTPUT] - 3단계 상속 + virtual destructor 체인
// 예상 출력을 순서대로 적어보세요. (생성 순서 vs 소멸 순서 비교 포인트)
// ============================================================
/*
class A {
public:
    A()  { cout << "A()"  << endl; }
    virtual ~A() { cout << "~A()" << endl; }
};
class B : public A {
public:
    B()  { cout << "B()"  << endl; }
    ~B() { cout << "~B()" << endl; }
};
class C : public B {
public:
    C()  { cout << "C()"  << endl; }
    ~C() { cout << "~C()" << endl; }
};

int main() {
    cout << "-- create --" << endl;
    A* p = new C();             // 1~3. 생성 시 출력 순서?
    cout << "-- delete --" << endl;
    delete p;                   // 4~6. 소멸 시 출력 순서?
    return 0;
}
*/


// ============================================================
// 문제 6 [BLANK] - predicate 다단계 비교 (3칸)
// 조건: "나이 적은 사람 먼저, 같으면 이름 알파벳 순"
// (predicate 흐름 — 우리가 길게 다뤘던 그 패턴, 직접 짜보는 연습)
// ============================================================

class Person {
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    string getName() const { return name; }
    int getAge()  const { return age; }
};

struct AgeThenNameCompare {
    bool operator()(const Person& p1, const Person& p2) const {
        if (p1.getAge() != p2.getAge())
            return p1.getAge();           // (1) "나이가 적은 쪽이 먼저"를 만족하는 식
        return p1.getName() < p2.getName();                  // (2) 나이가 같으면 무엇을 기준으로 비교?
    }
};

int main() {
    vector<Person> people = { Person("Charlie", 30), Person("Alice", 25), Person("Bob", 25) };
    sort(people.begin(), people.end(), AgeThenNameCompare());
    for (auto& p : people) cout << p.getName() << "(" << p.getAge() << ") ";
    cout << endl;
    // 예상 출력: Alice(25) Bob(25) Charlie(30)
    return 0;
}


// ============================================================
// 문제 7 [BLANK] - smart pointer + 다형성 + virtual destructor 종합 (4칸)
// _____ 를 채우고, (4)는 출력 결과를 직접 적어보세요.
// (smart pointer 불안 + destructor 체인 — 두 약점을 한 번에 묶은 문제)
// ============================================================
/*
template <typename T>
class SmartPtr {
    T* ptr;
public:
    SmartPtr(T* p) : ptr(p) {}
    ~SmartPtr()      { delete ptr; }              // (1) 메모리 해제
    T& operator*()   { return *ptr; }       // (2) 반환값
    T* operator->()  { return ptr; }       // (3) 반환값
};

class Animal {
public:
    virtual void speak() { cout << "..." << endl; }
    virtual ~Animal() { cout << "Animal destroyed" << endl; }
};
class Bird : public Animal {
public:
    void speak() override { cout << "Tweet" << endl; }
    ~Bird() { cout << "Bird destroyed" << endl; }
};

int main() {
    {
        SmartPtr<Animal> sp(new Bird());
        sp->speak();         // 1. 출력?
        (*sp).speak();       // 2. 출력?
    }
    // (4) 위 블록(스코프)이 끝나는 순간, 소멸 순서와 출력은? (Animal의 destructor가 virtual이라는 점에 주목)
    return 0;
}
*/


/*
int main() {
    cout << "문제 블록 주석 해제 후 실행하세요." << endl;
    return 0;
}
*/
