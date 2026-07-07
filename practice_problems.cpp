// ============================================================
// 기말고사 대비 연습문제 (inheritanceTest ~ abstractBaseClass)
// ============================================================
// 풀이 방법:
//   - [OUTPUT] 문제: 주석에 예상 출력 적어보기
//   - [BLANK]  문제: _____ 채우기
// 각 문제 블록을 main()에서 주석 해제해서 실행 확인
// ============================================================

#include <iostream>
using namespace std;


// ============================================================
// 문제 1 [OUTPUT] - Static vs Dynamic Binding 함정
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
class Vehicle {
public:
    void start() { cout << "Vehicle start" << endl; }
    virtual void move() { cout << "Vehicle move" << endl; }
    virtual ~Vehicle() { cout << "Vehicle destroyed" << endl; }
};

class Car : public Vehicle {
public:
    void start() { cout << "Car start" << endl; }
    void move() override { cout << "Car move" << endl; }
    ~Car() { cout << "Car destroyed" << endl; }
};

class ElectricCar : public Car {
public:
    void start() { cout << "ElectricCar start" << endl; }
    void move() override { cout << "ElectricCar move" << endl; }
    ~ElectricCar() { cout << "ElectricCar destroyed" << endl; }
};

int main() {
    Vehicle* v1 = new Car();
    Vehicle* v2 = new ElectricCar();
    Car*     v3 = new ElectricCar();

    v1->start();   // 1. ?
    v1->move();    // 2. ?

    v2->start();   // 3. ?
    v2->move();    // 4. ?

    v3->start();   // 5. ?
    v3->move();    // 6. ?

    delete v1;     // 7. ? (몇 줄 출력?)
    delete v2;     // 8. ? (몇 줄 출력?)
    delete v3;     // 9. ? (몇 줄 출력?)
    return 0;
}

*/

// ============================================================
// 문제 2 [BLANK] - Function Hiding & using
// _____ 를 채워 주석에 적힌 출력이 나오게 하세요.
// ============================================================
/*
class Printer {
public:
    void print() { cout << "Printer: default" << endl; }
    void print(int n) { cout << "Printer: " << n << endl; }
    void print(string s) { cout << "Printer: " << s << endl; }
};

class LaserPrinter : public Printer {
public:
    using Printer::print;  // Printer의 모든 print overload를 노출

    void print() { cout << "LaserPrinter: default" << endl; }
};

int main() {
    LaserPrinter lp;
    lp.print();       // LaserPrinter: default
    lp.print(42);     // Printer: 42          <- 이게 되려면?
    lp.print("hi");   // Printer: hi          <- 이게 되려면?
    return 0;
}
*/


// ============================================================
// 문제 3 [OUTPUT] - 생성자/소멸자 순서 + Virtual Inheritance
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
class Base {
public:
    Base()  { cout << "Base ctor" << endl; }
    ~Base() { cout << "Base dtor" << endl; }
};

class A : public virtual Base {
public:
    A()  { cout << "A ctor" << endl; }
    ~A() { cout << "A dtor" << endl; }
};

class B : public virtual Base {
public:
    B()  { cout << "B ctor" << endl; }
    ~B() { cout << "B dtor" << endl; }
};

class C : public A, public B {
public:
    C()  { cout << "C ctor" << endl; }
    ~C() { cout << "C dtor" << endl; }
};

int main() {
    C obj;   // 출력 순서는? (총 몇 줄?)
    return 0;
}

*/

// ============================================================
// 문제 4 [BLANK] - Abstract Base Class
// _____ 를 채워서 아래 조건을 만족하게 하세요.
//
// 조건:
//   - Shape는 인스턴스화 불가
//   - Circle과 Rectangle은 인스턴스화 가능
//   - draw()는 각 클래스에서 다르게 출력
//   - area()는 Shape에서 공통 구현 제공 (override 선택)
// ============================================================
/*
class Shape {
public:
    virtual void draw() = 0;          // pure virtual
    virtual void area() { cout << "Shape: area unknown" << endl; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Circle: draw" << endl; }
};

class Rectangle : public Shape {
public:
    void draw() override { cout << "Rectangle: draw" << endl; }
    void area() override { cout << "Rectangle: area = w*h" << endl; }
};

void render(Shape& s) {
    s.draw();
    s.area();
}

int main() {
    // Shape s;      // 이 줄은 왜 에러인가?
    Circle c;
    Rectangle r;
    render(c);
    render(r);
    return 0;
}
*/


// ============================================================
// 문제 5 [OUTPUT] - Private/Protected 상속 + Virtual 함정
// 예상 출력을 적고, 에러 나는 줄을 찾으세요.
// ============================================================

class Engine {
public:
    virtual void start() { cout << "Engine start" << endl; }
    void check()         { cout << "Engine check" << endl; }
};

class Car : private Engine {
public:
    void drive() {
        start();   // (a)
        check();   // (b)
        cout << "Car drive" << endl;
    }
};

class SportsCar : public Car {
public:
    void race() {
        drive();   // (c)
        //start();   // (d) <- 컴파일 에러? 아니면 정상?
        cout << "SportsCar race" << endl;
    }
};

int main() {
    Car c;
    c.drive();      // (e)
    //c.start();      // (f) <- 컴파일 에러? 아니면 정상?

    SportsCar sc;
    sc.race();      // (g)
    //sc.start();     // (h) <- 컴파일 에러? 아니면 정상?
    return 0;
}


/*
int main() {
    cout << "문제 블록 주석 해제 후 실행하세요." << endl;
    return 0;
}
*/