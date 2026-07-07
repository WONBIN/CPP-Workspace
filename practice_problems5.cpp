// ============================================================
// 기말고사 대비 연습문제 5 (4/6 ~ 5/13 범위)
// 함수포인터 / 람다 / 복사생성자 / 변환생성자 / operator<< /
// 메서드 hiding / for_each / deep copy / 다중상속 / private상속
// ============================================================
// [OUTPUT] : 출력 순서를 정확히 예측
// [BLANK]  : _____ 채우기
// [판별]   : 컴파일 에러 / 정상 판별 + 이유 서술
// 각 블록 주석 해제 후 컴파일/실행으로 검산
// ============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


// ============================================================
// 문제 1 [기초 / OUTPUT + BLANK] — 함수 포인터
// (4_6_functionPointerTest 연계)
// ============================================================
/*
void triple(int& x) { x *= 3; }
void negate_(int& x) { x = -x; }

int main() {
    void (*fp)(int&);          // (1) 이 선언이 의미하는 바를 한 줄로 설명하시오.

    int a = 5;
    fp = triple;
    fp(a);
    cout << a << endl;         // 2. 출력?

    fp = negate_;
    fp(a);
    cout << a << endl;         // 3. 출력?

    void (*ops[2])(int&) = {triple, negate_};  // (4) 이건 뭐를 선언한 것인가?
    int b = 4;
    for (int i = 0; i < 2; i++) ops[i](b);
    cout << b << endl;         // 5. 출력?
    return 0;
}
*/


// ============================================================
// 문제 2 [기초~중급 / BLANK + OUTPUT] — 람다 캡처 방식
// (4_13_whyLambda 연계)
// ============================================================
/*
int main() {
    int val = 10;
    auto f1 = [val](int x)  { return x + val; };        // (1) 캡처 방식: 값 / 참조 중 택일
    auto f2 = [&val](int x) { val += x; return val; };  // (2) 캡처 방식: 값 / 참조 중 택일

    val = 20;
    cout << f1(5) << endl;     // 3. 출력? (그리고 왜 그런지 한 줄로 설명)
    cout << f2(5) << endl;     // 4. 출력?
    cout << val   << endl;     // 5. 출력?

    vector<int> nums = {1, 3, 7, 2, 9, 4};
    sort(nums.begin(), nums.end(), [](int a, int b) { return a<b; });  // (6) 오름차순 정렬 조건

    int threshold = 6;
    int cnt = count_if(nums.begin(), nums.end(), [threshold](int x) { return x>threshold; }); // (7) threshold 초과 개수
    cout << cnt << endl;       // 8. 출력?
    return 0;
}
*/


// ============================================================
// 문제 3 [중급 / OUTPUT + 서술] — 복사 생성자 호출 시점 추적
// (4_29_copyMoveConstructor 연계)
// ============================================================
/*
class Box {
public:
    Box()           { cout << "Default" << endl; }
    Box(const Box&) { cout << "Copy"    << endl; }
    ~Box()          { cout << "Dtor"    << endl; }
};

Box makeBox(Box b) {        // 주목: 파라미터를 값으로 받음
    cout << "makeBox" << endl;
    return b;               // 주목: 값으로 반환
}

int main() {
    cout << "=A=" << endl;
    Box b1;                 // 1. 출력?

    cout << "=B=" << endl;
    Box b2 = b1;            // 2. 출력?

    cout << "=C=" << endl;
    makeBox(b1);   // 3~4. 복사 생성자가 어느 시점에 호출되는가?
                            //      (파라미터 전달 / 값 반환 각각을 구분해서 설명)
    cout << "=end=" << endl;
    return 0;               // 5. 소멸 순서와 출력은? (b1, b2, b3 전부 포함)
}
// (6) "Box b2 = b1;" 과 "Box b2; b2 = b1;" 의 차이를
//      복사 생성자 vs 복사 대입 연산자 측면에서 설명하시오.
*/


// ============================================================
// 문제 4 [중급 / 판별 + 서술] — implicit / explicit 변환 생성자
// (4_13_cosntructorConvertType 연계)
// ============================================================
/*
class Meter {
    double value;
public:
    Meter(double v) : value(v) {}        // implicit 변환 허용 상태
    void show() const { cout << value << "m" << endl; }
};

void printMeter(Meter m) { m.show(); }

int main() {
    Meter m1 = 3.5;          // (a) 컴파일 에러 / 정상? 이유는?
    printMeter(5.0);          // (b) 컴파일 에러 / 정상? 이유는?
    Meter m2(2.0);            // (c) 컴파일 에러 / 정상? 이유는?
    return 0;
}
// (d) 생성자 앞에 explicit 를 붙이면, (a)(b)(c) 중 어느 줄이 에러가 되는가?
// (e) (c)는 explicit가 있어도 왜 에러가 되지 않는가?
*/


// ============================================================
// 문제 5 [중급 / BLANK + 서술] — operator<< (friend 함수) 오버로딩
// (4_15_operatorOverloading 연계)
// ============================================================
/*
class Vec3 {
    double x, y, z;
public:
    Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
    Vec3 operator+(const Vec3& o) const { return Vec3(x+o.x, y+o.y, z+o.z); }

    friend ostream& (ostream& os, const Vec3& v) {   // (1) 반환 타입
        os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
        return os;                                        // (2) 반환값
    }
};

int main() {
    Vec3 a(1, 2, 3), b(4, 5, 6);
    cout << a << endl;                   // 3. 출력?
    cout << a + b << endl;               // 4. 출력?
    cout << a << " and " << b << endl;  // 5. 출력?
    // (6) operator<<를 멤버 함수가 아닌 friend 함수로 정의해야 하는 이유를 설명하시오.
    // (7) 반환 타입이 void가 아니라 ostream& 이어야 하는 이유를 설명하시오.
    return 0;
}
*/


// ============================================================
// 문제 6 [중급 / OUTPUT + 판별] — 메서드 hiding & 스코프 해상 연산자
// (5_11_inheritanceTest3 연계)
// ============================================================
/*
class Base {
public:
    void hello()      { cout << "Base::hello()"     << endl; }
    void hello(int x) { cout << "Base::hello(" << x << ")" << endl; }
    virtual void greet() { cout << "Base::greet()" << endl; }
};

class Child : public Base {
public:
    void hello() { cout << "Child::hello()" << endl; }   // Base의 hello(int)도 함께 가려짐
    void greet() override { cout << "Child::greet()" << endl; }
};

int main() {
    Child c;
    c.hello();              // 1. 출력?
    //c.hello(42);         // (2) 주석 풀면? 컴파일 에러 / 정상? 이유는?
    c.Base::hello(42);      // 3. 출력?

    Base* bp = &c;
    bp->hello();            // 4. 출력? (hello가 virtual이 아님에 주목) // static binding
    bp->greet();            // 5. 출력? (greet는 virtual) //dyna,mic
    return 0;
}
// (6) 4번과 5번의 출력이 다른 이유를 "정적 바인딩 vs 동적 바인딩" 용어로 설명하시오.

*/

// ============================================================
// 문제 7 [중급 / BLANK] — for_each: 함수포인터 vs functor vs 람다
// (4_13_STL-Vector-Lambda 연계)
// ============================================================

void printDouble(int x) { cout << x * 2 << " "; }

struct Adder {
    int n;
    Adder(int n) : n(n) {}
    void operator()(int x) const { cout << x + n << " "; }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // (1) 함수 포인터로 전달 — 각 원소를 2배로 출력
    for_each(v.begin(), v.end(), printDouble);
    cout << endl;

    // (2) functor로 전달 — 각 원소에 10을 더해서 출력
    for_each(v.begin(), v.end(), Adder(10));
    cout << endl;

    // (3) 람다로 전달 — 각 원소의 제곱을 출력
    for_each(v.begin(), v.end(), [](int x) { return x*x; });
    cout << endl;

    // (4) 함수포인터 대비 functor/람다의 가장 큰 장점을 한 줄로 설명하시오.
    return 0;
}



// ============================================================
// 문제 8 [중급~고급 / OUTPUT + 서술] — deep copy vs shallow copy
// (5_4_MyStringTest 연계)
// ============================================================
/*
class Buffer {
    int* data;
    int  size;
public:
    Buffer(int sz) : size(sz) {
        data = new int[sz];
        for (int i = 0; i < sz; i++) data[i] = i * 10;
        cout << "Ctor(size=" << sz << ")" << endl;
    }
    Buffer(const Buffer& o) : size(o.size) {    // deep copy
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = o.data[i];
        cout << "CopyCtor" << endl;
    }
    ~Buffer() {
        delete[] data;
        cout << "Dtor(size=" << size << ")" << endl;
    }
    void  set(int idx, int val) { data[idx] = val; }
    int   get(int idx) const    { return data[idx]; }
};

int main() {
    Buffer b1(3);             // 1. 출력?
    Buffer b2 = b1;           // 2. 출력?
    b2.set(0, 999);
    cout << b1.get(0) << endl; // 3. 출력? b1이 영향받지 않는 이유는?
    cout << b2.get(0) << endl; // 4. 출력?
    return 0;
    // 5. 소멸 순서와 출력은? (b1, b2 순서 포함)
}
// (6) 복사 생성자에서 "data = o.data;" 만 했다면 (shallow copy)
//     b2.set(0, 999) 이후 어떤 문제가 생기는가? 소멸 시 어떤 추가 문제가 생기는가?
*/


// ============================================================
// 문제 9 [고급 / OUTPUT + 서술] — 다중 상속 + diamond + virtual 상속
// (5_13_MultipleInheritance 연계)
// ============================================================
/*
class Base {
public:
    Base()  { cout << "Base()"  << endl; }
    ~Base() { cout << "~Base()" << endl; }
    void identify() { cout << "I am Base" << endl; }
};

class Left : public virtual Base {
public:
    Left()  { cout << "Left()"  << endl; }
    ~Left() { cout << "~Left()" << endl; }
};

class Right : public virtual Base {
public:
    Right()  { cout << "Right()"  << endl; }
    ~Right() { cout << "~Right()" << endl; }
};

class Bottom : public Left, public Right {
public:
    Bottom()  { cout << "Bottom()"  << endl; }
    ~Bottom() { cout << "~Bottom()" << endl; }
};

int main() {
    Bottom b;     // 1~5. 생성자 출력 순서는? (Base가 몇 번 생성되는지에 주목)
    b.identify(); // 6. 출력? (에러가 나는지 안 나는지도 판단)
    return 0;     // 7~11. 소멸자 출력 순서는?
}
// (12) virtual 없이 Left, Right가 Base를 일반 상속하면 Bottom 객체에서 어떤 문제가 생기는가?
// (13) virtual 상속을 쓰면 그 문제가 어떻게 해결되는가?
*/


// ============================================================
// 문제 10 [고급 / OUTPUT + 판별] — private 상속 + virtual dispatch 종합
// (5_13_privateInheritance + 5_13_virtualInheritance 연계)
// ============================================================
/*
class Engine {
public:
    virtual void start() { cout << "Engine::start()" << endl; }
    void stop()          { cout << "Engine::stop()"  << endl; }
};

class TurboEngine : public Engine {
public:
    void start() override { cout << "TurboEngine::start()" << endl; }
};

class Car : private Engine {
public:
    void drive() {
        start();                         // (1) 어떤 start()가 호출되나? 그 이유는?
        cout << "Car driving" << endl;
        stop();
    }
};

class SportsCar : private TurboEngine {
public:
    void drive() {
        start();                         // (2) 어떤 start()가 호출되나? 그 이유는?
        cout << "SportsCar driving" << endl;
    }
};

int main() {
    Car c;
    c.drive();              // 3~5. 출력?
    // c.start();           // (6) 주석 풀면? 컴파일 에러 / 정상? 이유는?

    cout << "---" << endl;
    SportsCar sc;
    sc.drive();             // 7~8. 출력?

    // (9) Car와 SportsCar에서 start()의 출력 결과가 다른 이유를 설명하시오.
    //     (힌트: private 상속이 virtual dispatch 자체를 막지는 않는다)
    return 0;
}
*/
