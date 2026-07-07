// ============================================================================
// 모의 기말고사 (4/8 ~ 6/1 범위, set/map 제외)
// ============================================================================
// - 총 17문제 / 75분
// - 앞부분(1~6번)은 가볍게, 뒤로 갈수록(12~17번) 트리키하고 무거워짐
// - [OUTPUT] : 출력 순서를 정확히 예측해서 적기
// - [BLANK]  : _____ 채우기 (번호별로)
// - 일부 문제엔 "컴파일 에러 / 런타임 에러 / 정상" 판별 + 이유 서술 포함
// - 각 블록은 /* */ 로 묶여 있으니, 풀 때 블록 주석 해제 후 컴파일/실행해서 검산
// ============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;


// ============================================================================
// 1번 [기초 / OUTPUT] - 기본 operator overloading
// ============================================================================
/*
class Vector2D {
    int x, y;
public:
    Vector2D(int x, int y) : x(x), y(y) {}
    Vector2D operator+(const Vector2D& o) const { return Vector2D(x + o.x, y + o.y); }
    void show() const { cout << "(" << x << ", " << y << ")" << endl; }
};

int main() {
    Vector2D a(1, 2), b(3, 4);
    Vector2D c = a + b;
    c.show();   // 1. 출력?
    a.show();   // 2. 출력?
    return 0;
}
*/

// ============================================================================
// 2번 [기초 / OUTPUT] - 상속 생성자·소멸자 호출 순서 (스택 객체, non-virtual)
// ============================================================================
/*
class Animal {
public:
    Animal()  { cout << "Animal()"  << endl; }
    ~Animal() { cout << "~Animal()" << endl; }
};
class Dog : public Animal {
public:
    Dog()  { cout << "Dog()"  << endl; }
    ~Dog() { cout << "~Dog()" << endl; }
};

int main() {
    Dog d;
    return 0;
}
// 1~4. 출력 순서를 적어보세요 (생성 + 소멸 전부 포함)
*/


// ============================================================================
// 3번 [기초 / BLANK] - 기본 functor (1칸)
// ============================================================================
/*
class IsEven {
public:
    bool operator()(int x) const {
        return x % 2 == 0 ;          // (1) x가 짝수인지 판별하는 식
    }
};

int main() {
    IsEven isEven;
    cout << isEven(4) << endl;   // 1
    cout << isEven(7) << endl;   // 0
    return 0;
}
*/


// ============================================================================
// 4번 [기초~중급 / OUTPUT] - prefix vs postfix 기본 추적
// ============================================================================
/*
class Counter {
    int val;
public:
    Counter(int v) : val(v) {}
    Counter& operator++()    { ++val; return *this; }
    Counter  operator++(int) { Counter tmp(val); ++val; return tmp; }
    int getVal() const { return val; }
};

int main() {
    Counter a(5);
    Counter b = a++;
    cout << a.getVal() << " " << b.getVal() << endl;   // 1. 출력?

    Counter c = ++a;
    cout << a.getVal() << " " << c.getVal() << endl;   // 2. 출력?
    return 0;
}
*/

// ============================================================================
// 5번 [중급 / 판별+서술] - public/protected/private 접근 제어
// 각 줄에 대해 "컴파일 에러" 인지 "정상" 인지 판단하고, 그 이유를 한 줄로 적으세요.
// ============================================================================
/*
class Base {
private:
    int secretA;
protected:
    int secretB;
public:
    int openC;
    Base() : secretA(1), secretB(2), openC(3) {}
};

class Derived : public Base {
public:
    void show() {
        cout << secretB << endl;     // (a) 컴파일 에러 / 정상?
        cout << openC  << endl;      // (b) 컴파일 에러 / 정상?
        // cout << secretA << endl;  // (c) 이 줄의 주석을 풀면? 컴파일 에러 / 정상? 이유는?
    }
};

int main() {
    Derived d;
    d.show();
    cout << d.openC << endl;          // (d) 컴파일 에러 / 정상?
    // cout << d.secretB << endl;     // (e) 이 줄의 주석을 풀면? 컴파일 에러 / 정상? 이유는?
    return 0;
}
*/


// ============================================================================
// 6번 [중급 / BLANK + 서술] - 캐스팅 연산자 & 파생 비교연산자
// ============================================================================
/*
class Temperature {
    double celsius;
public:
    Temperature(double c) : celsius(c) {}
    operator double() const { return celsius; }                       // 캐스팅 연산자
    bool operator<(const Temperature& o)  const { return celsius < o.celsius; }
    bool operator==(const Temperature& o) const { return celsius == o.celsius; }
    bool operator!=(const Temperature& o) const { return !(celsius == o.celsius); }    // (1)
};

int main() {
    Temperature t1(25.5), t2(30.0);
    cout << (double)t1 << endl;       // 1. 출력?
    cout << (t1 < t2)  << endl;       // 2. 출력?
    cout << (t1 != t2) << endl;       // 3. 출력?

    double avg = (t1 + t2) / 2;       // (2) 이 줄은 컴파일 에러 없이 정상 동작합니다.
                                      //     avg의 값은? 그리고 Temperature끼리 + 연산이
                                      //     어떻게 가능한지 그 이유를 설명하세요.
    cout << avg << endl;              // 4. 출력?
    return 0;
}
*/


// ============================================================================
// 7번 [중급 / OUTPUT] - virtual function / 다형성 기본
// ============================================================================
/*
class Shape {
public:
    virtual void draw() const { cout << "Shape" << endl; }
    void info() const { cout << "I am a "; draw(); }   // info는 virtual이 아님!
};
class Square : public Shape {
public:
    void draw() const override { cout << "Square" << endl; }
};
class Triangle : public Shape {
public:
    void draw() const override { cout << "Triangle" << endl; }
};

int main() {
    Shape* shapes[2];
    shapes[0] = new Square();
    shapes[1] = new Triangle();

    for (int i = 0; i < 2; i++) {
        shapes[i]->info();       // 1~2. 출력?
    }
    for (int i = 0; i < 2; i++) delete shapes[i];
    return 0;
}
// (3) info() 자체는 virtual이 아닌데도 draw()가 객체 종류별로 다르게 호출되는 이유를 한 줄로 설명하세요.
*/


// ============================================================================
// 8번 [중급 / BLANK + 서술] - Lambda 함수 (캡처 방식)
// ============================================================================

int main() {
    vector<int> nums = {3, 7, 2, 9, 4, 1};

    int threshold = 5;
    auto countAbove = [&threshold](int x) { return x > threshold; };   // (1) threshold를 "값으로" 캡처하는 표기

    int cnt = 0;
    for (int n : nums) if (countAbove(n)) cnt++;
    cout << cnt << endl;             // 2. 출력?

    threshold = 1;                   // 람다 생성 "이후" threshold 값을 변경
    cout << countAbove(2) << endl;   // 3. 출력? (그리고 그 이유를 한 줄로 설명하세요)

    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });  // (4) 내림차순 정렬 조건
    for (int n : nums) cout << n << " ";
    cout << endl;                    // 5. 출력?
    return 0;
}



// ============================================================================
// 9번 [중급 / OUTPUT + 판별] - custom iterator 순회 & scope 함정
// ============================================================================
/*
class CharBox {
    char data[4];
public:
    struct Iter {
        char* ptr;
        Iter(char* p) : ptr(p) {}
        char& operator*()  { return *ptr; }
        Iter& operator++() { ++ptr; return *this; }
        bool operator!=(const Iter& o) const { return ptr != o.ptr; }
    };
    CharBox() { data[0]='a'; data[1]='b'; data[2]='c'; data[3]='d'; }
    Iter begin() { return Iter(data); }
    Iter end()   { return Iter(data + 4); }
};

int main() {
    CharBox box;
    for (char& c : box) c = toupper(c);

    string result = "";
    for (char c : box) result += c;
    cout << result << endl;             // 1. 출력?

    int cnt = 0;
   // for (Iter it = box.begin(); it != box.end(); ++it) cnt++;   // (2) 컴파일 에러 / 정상? 이유는?
    cout << cnt << endl;
    return 0;
}
*/


// ============================================================================
// 10번 [중급~고급 / BLANK] - predicate 다단계 비교 (pair 활용)
// 조건: "점수 높은 사람 먼저, 동점이면 이름 오름차순"
// ============================================================================
/*
struct ScoreThenNameDesc {
    bool operator()(const pair<string,int>& p1, const pair<string,int>& p2) const {
        if (p1.second != p2.second)
            return p1.second > p2.second;         // (1) 점수가 높은 쪽이 먼저
        return p1.first < p2.first;             // (2) 점수가 같으면 이름 오름차순
    }
};

int main() {
    vector<pair<string,int>> students = { {"Charlie",80}, {"Alice",90}, {"Bob",90}, {"Dave",80} };
    sort(students.begin(), students.end(), ScoreThenNameDesc());
    for (auto& s : students) cout << s.first << "(" << s.second << ") ";
    cout << endl;
    // 예상 출력: Alice(90) Bob(90) Charlie(80) Dave(80)
    return 0;
}
*/


// ============================================================================
// 11번 [고급 / OUTPUT + 판별] - smart pointer 종합
// (힌트: "= delete"는 해당 함수의 사용을 컴파일 타임에 명시적으로 금지한다는 뜻입니다)
// ============================================================================
/*
template <typename T>
class Box {
    T* ptr;
public:
    Box(T* p) : ptr(p) {}
    ~Box() { delete ptr; }
    T& operator*()  { return *ptr; }
    T* operator->() { return ptr; }
    Box(const Box& other) = delete;     // 복사 생성자 사용 금지
};

class Robot {
    string name;
public:
    Robot(string n) : name(n) { cout << name << " activated" << endl; }
    ~Robot() { cout << name << " deactivated" << endl; }
    void greet() { cout << name << ": Hello!" << endl; }
};

int main() {
    Box<Robot> b1(new Robot("R2D2"));
    b1->greet();             // 1. 출력?
    (*b1).greet();           // 2. 출력?

    // Box<Robot> b2 = b1;   // (3) 이 줄의 주석을 풀면? 컴파일 에러 / 정상? 이유는?

    return 0;
    // 4. main이 끝나면서 일어나는 일과 출력은?
}
*/


// ============================================================================
// 12번 [고급 / OUTPUT] - virtual destructor 비교 (non-virtual 함정!)
// 11번 직전 문제와 달리, 이번엔 destructor가 virtual이 "아닙니다". 잘 보세요.
// ============================================================================
/*
class Vehicle {
public:
    Vehicle()  { cout << "Vehicle created"   << endl; }
   virtual  ~Vehicle() { cout << "Vehicle destroyed" << endl; }   // virtual이 아님!
};
class Car : public Vehicle {
public:
    Car()  { cout << "Car created"   << endl; }
    ~Car()  { cout << "Car destroyed" << endl; }
};

int main() {
    cout << "--- A: 스택 객체 ---" << endl;
    { Car c; }                     // 1~4. 출력?

    cout << "--- B: Vehicle* 포인터 + delete (non-virtual) ---" << endl;
    Vehicle* v = new Car();
    delete v;                      // 5~7. 출력? 그리고 ~Car()가 호출되는지 안 되는지,
                                   //      왜 그런지, 어떤 문제가 생길 수 있는지 서술하세요.
    return 0;
}
*/


// ============================================================================
// 13번 [고급 / OUTPUT + 판별] - protected 상속 2단계 + virtual 결합
// (네가 가장 약하다고 짚은 영역 — "누가 호출하느냐"를 끝까지 추적해보세요)
// ============================================================================
/*
class Component {
public:
    virtual void activate() { cout << "Component activated" << endl; }
    virtual ~Component() { cout << "~Component" << endl; }
};

class Module : protected Component {
public:
    void run() {
        activate();                  // (a) 컴파일 에러 / 정상?
        cout << "Module running" << endl;
    }
};

class SubModule : public Module {
public:
    void test() {
        activate();                  // (b) 컴파일 에러 / 정상? (힌트: protected 상속을 한 단계 더 거치면 접근 등급이 어떻게 이어질까?)
    }
};

int main() {
    SubModule sm;
    sm.run();              // 1~2. 출력?
    // sm.activate();      // (c) 이 줄의 주석을 풀면? 컴파일 에러 / 정상? 이유는?
    return 0;
}

*/

// ============================================================================
// 14번 [고급 / OUTPUT] - functor 상태 + 복사 의미론 + STL 알고리즘 결합
// ============================================================================
/*
class Tracker {
    vector<int> seen;
public:
    void operator()(int x) {
        seen.push_back(x);
        cout << "size=" << seen.size() << " last=" << x << endl;
    }
    int total() const { return (int)seen.size(); }
};

int main() {
    vector<int> data = {10, 20, 30};
    Tracker t1;

    for (int x : data) t1(x);                       // 1~3. 출력?
    cout << "t1 total: " << t1.total() << endl;     // 4. 출력?

    Tracker t2 = t1;
    t2(99);                                          // 5. 출력?
    cout << "t1 total: " << t1.total() << endl;     // 6. 출력?
    cout << "t2 total: " << t2.total() << endl;     // 7. 출력?

    for_each(data.begin(), data.end(), t1);         // (8) 이 줄에서 출력이 발생하나요? 발생한다면 무엇이,
                                                     //     왜 그렇게 출력되는지 설명하세요.
                                                     //     (힌트: for_each는 functor를 "값"으로 전달받습니다)
    cout << "t1 total: " << t1.total() << endl;     // 9. 출력? (그리고 그 이유는?)
    return 0;
}
*/


// ============================================================================
// 15번 [고급 / OUTPUT] - prefix/postfix 이중 체이닝 + 캐스팅 연산자 (재검증용 함정)
// ============================================================================
/*
class Gauge {
    int level;
public:
    Gauge(int l) : level(l) {}
    Gauge& operator++()    { ++level; return *this; }
    Gauge  operator++(int) { Gauge tmp(level); ++level; return tmp; }
    operator int() const { return level; }
};

int main() {
    Gauge g(10);

    int a = (g++)++;                          // 1. a = ?  g = ?  (함정! 천천히 단계별로 추적해보세요)
    cout << a << " " << (int)g << endl;       // 2. 출력?

    int b = ++(++g);                          // 3. b = ?  g = ?
    cout << b << " " << (int)g << endl;       // 4. 출력?
    return 0;
}

*/

// ============================================================================
// 16번 [고급 / BLANK] - Lambda + predicate + 알고리즘 종합
// ============================================================================
/*
int main() {
    vector<string> words = {"kiwi", "fig", "banana", "egg", "date", "ant"};

    // (1) 길이가 4 이상인 단어만 true를 반환하는 predicate 람다
    auto isLong = [](const string& w) { return w.length() >= 4; };
    int longCount = count_if(words.begin(), words.end(), isLong);
    cout << longCount << endl;        // 2. 출력?

    // 조건: "길이가 짧은 단어 먼저, 같은 길이면 알파벳 순"
    sort(words.begin(), words.end(),
        [](const string& a, const string& b) {
            if (a.length() != b.length())
                return a.length() < b.length();          // (3) 길이가 짧은 쪽이 먼저
            return a < b;              // (4) 길이가 같으면 무엇을 기준으로?
        });

    for (auto& w : words) cout << w << " ";
    cout << endl;                       // 5. 출력?
    return 0;
}
*/

// ============================================================================
// 17번 [최종 종합 / OUTPUT] - 상속 + 다형성 + functor + 복사의미론 + 소멸자 체인
// 이번 학기에 다룬 핵심 주제를 한 번에 엮은 마지막 문제입니다. 천천히, 순서대로 추적하세요.
// ============================================================================
/*
class Employee {
protected:
    string name;
public:
    Employee(string n) : name(n) { cout << name << " hired" << endl; }
    virtual void work() const { cout << name << " works generically" << endl; }
    virtual ~Employee() { cout << name << " left (Employee)" << endl; }
};

class Manager : public Employee {
    int teamSize;
public:
    Manager(string n, int t) : Employee(n), teamSize(t) { cout << name << " promoted to manager" << endl; }
    void work() const override { cout << name << " manages " << teamSize << " people" << endl; }
    ~Manager() { cout << name << " left (Manager)" << endl; }
};

class Logger2 {
    int callCount;
public:
    Logger2() : callCount(0) {}
    void operator()(const Employee* e) {
        callCount++;
        cout << "[log " << callCount << "] ";
        e->work();
    }
    int getCount() const { return callCount; }
};

int main() {
    vector<Employee*> staff;
    staff.push_back(new Employee("Tom"));      // 1. 출력?
    staff.push_back(new Manager("Anna", 5));   // 2~3. 출력? (생성자 호출 순서 주의)

    Logger2 logger;
    for (Employee* e : staff) logger(e);              // 4~5. 출력?
    cout << "logged: " << logger.getCount() << endl;  // 6. 출력?

    Logger2 logger2 = logger;
    logger2(staff[0]);                                  // 7. 출력?
    cout << "logger: "  << logger.getCount()  << endl;  // 8. 출력?
    cout << "logger2: " << logger2.getCount() << endl;  // 9. 출력?

    for (Employee* e : staff) delete e;       // 10~14. 출력? (소멸 순서를 정확히 추적하세요)

    return 0;
}
*/


/*
int main() {
    cout << "문제 블록 주석 해제 후 실행하세요." << endl;
    return 0;
}
*/
