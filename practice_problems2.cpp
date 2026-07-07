// ============================================================
// 기말고사 대비 연습문제 2 (operatorOverloading + smartPointer)
// ============================================================
// 풀이 방법:
//   - [OUTPUT] 문제: 주석에 예상 출력 적어보기
//   - [BLANK]  문제: _____ 채우기 (각 빈칸에 번호 표시)
// 각 문제 블록 주석 해제 후 실행 확인
// ============================================================

#include <iostream>
#include <sstream>
#include <string>
using namespace std;


// ============================================================
// 문제 1 [OUTPUT] - prefix vs postfix chaining 함정
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
class Counter {
    int val;
public:
    Counter(int v) : val(v) {}
    Counter& operator++() { ++val; return *this; }
    Counter  operator++(int) { Counter tmp(val); ++val; return tmp; }
    Counter& operator--() { --val; return *this; }
    Counter  operator--(int) { Counter tmp(val); --val; return tmp; }
    void show() { cout << "val: " << val << endl; }
};

int main() {
    Counter a(5);

    Counter b = a++;   // 1. b.val = ?  a.val = ?
    b.show();          // 2. 출력?
    a.show();          // 3. 출력?

    Counter c = ++a;   // 4. c.val = ?  a.val = ?
    c.show();          // 5. 출력?
    a.show();          // 6. 출력?

    ++(++a);           // 7. a.val = ?
    a.show();          // 8. 출력?

    (a++)++;           // 9. a.val = ?  (함정!)
    a.show();          // 10. 출력?

    return 0;
}
*/


// ============================================================
// 문제 2 [OUTPUT] - prefix vs postfix 반환값 추적
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
class Score {
    int s;
public:
    Score(int v) : s(v) {}
    Score& operator++() { ++s; return *this; }
    Score  operator++(int) { Score tmp(s); ++s; return tmp; }
    operator int() { return s; }
};

int main() {
    Score x(10);

    int a = x++;    // 1. a = ?  x = ?
    int b = ++x;    // 2. b = ?  x = ?
    int c = x++;    // 3. c = ?  x = ?

    cout << a << endl;   // 4. 출력?
    cout << b << endl;   // 5. 출력?
    cout << c << endl;   // 6. 출력?
    cout << (int)x << endl; // 7. 출력?

    return 0;
}
*/


// ============================================================
// 문제 3 [BLANK] - operator overloading 빈칸 채우기
// 아래 조건을 만족하게 _____ 를 채우세요.
//
// 조건:
//   - Box끼리 + 하면 volume 합산한 새 Box 반환
//   - Box를 int로 캐스팅하면 volume 반환
//   - ++Box는 width만 1 증가, 원본 반환
//   - Box++ 는 증가 전 복사본 반환, 원본 width 1 증가
// ============================================================
/*
class Box {
    int width, height, depth;
public:
    Box(int w, int h, int d) : width(w), height(h), depth(d) {}
    int volume() { return width * height * depth; }

    Box operator+(const Box& other) {                    // (1) 반환타입
        return Box(width + other.width, height, depth);
    }

    operator int() { return volume(); }                  // (2) 캐스팅 타입

    Box& operator++() {                                   // (3) 반환타입
        ++width;
        return *this;                                      // (4) 뭘 반환?
    }

    Box operator++(int) {                      // (5) 반환타입, (6) 더미 파라미터
        Box tmp(width, height, depth);
        ++width;
        return tmp;
    }

    void show() { cout << "volume: " << volume() << endl; }
};

int main() {
    Box b1(2, 3, 4);
    Box b2(1, 3, 4);

    Box b3 = b1 + b2;
    b3.show();              // volume: ?

    cout << (int)b1 << endl; // 출력: ?

    ++b1;
    b1.show();              // volume: ?

    Box b4 = b1++;
    b4.show();              // volume: ?
    b1.show();              // volume: ?

    return 0;
}

*/

// ============================================================
// 문제 4 [BLANK] - smart pointer + operator overloading
// _____ 를 채워서 main이 정상 실행되게 하세요.
// ============================================================
/*
template <typename T>
class MyPtr {
    T* ptr;                                     // (1) 멤버 변수 타입

public:
    MyPtr(T* p) : ptr(p) {}
    ~MyPtr() { delete ptr; }                          // (2) 소멸자

    T& operator*()  { return *ptr; }   // (3) 반환타입, (4) 반환값
    T* operator->() { return ptr; }   // (5) 반환타입, (6) 반환값
};

class Item {
    string name;
public:
    Item(string n) : name(n) {}
    void show() { cout << "Item: " << name << endl; }
};

int main() {
    MyPtr<Item> p(new Item("sword"));
    p->show();           // Item: sword
    (*p).show();         // Item: sword
    return 0;
}
*/


// ============================================================
// 문제 5 [OUTPUT] - operator= 와 비교 연산자 추적
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
class Date {
    int day, month, year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day; month = other.month; year = other.year;
        }
        return *this;
    }
    bool operator==(const Date& o) const {
        return day==o.day && month==o.month && year==o.year;
    }
    bool operator<(const Date& o) const {
        if (year != o.year)   return year < o.year;
        if (month != o.month) return month < o.month;
        return day < o.day;
    }
    bool operator>(const Date& o) const  { return o < *this; }
    bool operator!=(const Date& o) const { return !(*this == o); }

    void show() { cout << day << "/" << month << "/" << year << endl; }
};

int main() {
    Date d1(1, 1, 2026);
    Date d2(15, 6, 2026);
    Date d3(1, 1, 2026);

    cout << (d1 == d3) << endl;   // 1. 출력?
    cout << (d1 == d2) << endl;   // 2. 출력?
    cout << (d1 != d2) << endl;   // 3. 출력?
    cout << (d1 < d2)  << endl;   // 4. 출력?
    cout << (d2 > d1)  << endl;   // 5. 출력?

    d3 = d2;
    d3.show();                    // 6. 출력?
    cout << (d3 == d2) << endl;   // 7. 출력?

    Date d4 = d1;                 // 8. 이건 operator= 호출? (yes/no)
    d4.show();                    // 9. 출력?

    return 0;
}
*/

// ============================================================
// 문제 6 [OUTPUT] - functor (operator()) 상태 추적
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
class Multiplier {
    int factor;
public:
    int callCount;
    Multiplier(int f) : factor(f), callCount(0) {}
    int operator()(int x) {
        callCount++;
        return x * factor;
    }
};

int main() {
    Multiplier triple(3);

    cout << triple(4)  << endl;   // 1. 출력?
    cout << triple(10) << endl;   // 2. 출력?
    cout << triple(0)  << endl;   // 3. 출력?
    cout << triple.callCount << endl; // 4. 출력?

    Multiplier doubler(2);
    cout << doubler(triple(5)) << endl; // 5. 출력? (함정!)

    return 0;
}
*/


// ============================================================
// 문제 7 [BLANK] - operator[] 빈칸 채우기
// _____ 를 채워서 main이 정상 실행되게 하세요.
// ============================================================
/*
class SafeArray {
    int arr[10];
    int size;
public:
    SafeArray(int s) : size(s) {
        for(int i=0; i<size; i++) arr[i] = 0;
    }

    int& operator[](int idx) {           // (1) 원소 타입
        if (idx < 0 || idx >= size)
            throw out_of_range("out of range");
        return arr[idx];
    }
};

int main() {
    SafeArray sa(5);
    sa[0] = 100;
    sa[2] = 200;
    cout << sa[0] << endl;   // 100
    cout << sa[2] << endl;   // 200

    try {
        sa[10] = 999;        // 예외 발생
    } catch (out_of_range& e) {
        cout << "caught: " << e.what() << endl;
    }
    return 0;
}
*/


// ============================================================
// 문제 8 [OUTPUT] - prefix chaining + operator= 조합 함정
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
class Val {
    int v;
public:
    Val(int x) : v(x) {}
    Val& operator++() { ++v; return *this; }
    Val  operator++(int) { Val tmp(v); ++v; return tmp; }
    Val& operator=(const Val& o) { v = o.v; return *this; }
    operator int() { return v; }
};

int main() {
    Val a(3);
    Val b(0);

    b = ++a;             // 1. a = ?  b = ?
    cout << (int)a << endl; // 2. 출력?
    cout << (int)b << endl; // 3. 출력?

    b = a++;             // 4. a = ?  b = ?
    cout << (int)a << endl; // 5. 출력?
    cout << (int)b << endl; // 6. 출력?

    Val c = ++(++a);     // 7. a = ?  c = ?
    cout << (int)a << endl; // 8. 출력?
    cout << (int)c << endl; // 9. 출력?

    Val d = (a++)++;     // 10. a = ?  d = ? (함정!)
    cout << (int)a << endl; // 11. 출력?
    cout << (int)d << endl; // 12. 출력?

    return 0;
}
*/

// ============================================================
// 문제 9 [BLANK] - operator overloading 종합 빈칸 (8칸)
// _____ 를 채워서 아래 출력이 나오게 하세요.
//
// 예상 출력:
//   before: 10
//   after++: 10
//   after: 11
//   after++: 11
//   after: 13
//   sum: 23
// ============================================================
/*
class Num {
    int n;
public:
    Num(int x) : n(x) {}

    // postfix
    Num operator++(int) {        // (1) operator 이름, (2) 더미 파라미터
        Num tmp = *this;                 // (3) 복사본 저장
        ++n;                           // (4) 원본 증가
        return tmp;                              // 복사본 반환
    }

    // prefix
    Num& operator++() {                       // (5) operator 이름
        ++n;                          // (6) 증가 연산자
        return *this;                    // (7) 원본 반환
    }

    Num operator+(const Num& o) { return Num(n + o.n); }

    operator int() { return n; }     // (8) 반환값
};

int main() {
    Num a(10);
    cout << "before: "   << (int)a       << endl;
    Num b = a++;
    cout << "after++: "  << (int)b       << endl;
    cout << "after: "    << (int)a       << endl;
    Num c = a++;
    cout << "after++: "  << (int)c       << endl;
    ++(++a);
    cout << "after: "    << (int)a       << endl;
    Num d = a + b;
    cout << "sum: "      << (int)d       << endl;
    return 0;
}
*/


// ============================================================
// 문제 10 [OUTPUT] - smart pointer + virtual 조합 함정
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
template <typename T>
class MyPtr {
    T* ptr;
public:
    MyPtr(T* p) : ptr(p) {}
    ~MyPtr() { delete ptr; }
    T& operator*()  { return *ptr; }
    T* operator->() { return ptr; }
};

class Animal {
public:
    virtual void speak() { cout << "Animal speak" << endl; }
    virtual ~Animal()    { cout << "Animal destroyed" << endl; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Dog bark" << endl; }
    ~Dog()                { cout << "Dog destroyed" << endl; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "Cat meow" << endl; }
    ~Cat()                { cout << "Cat destroyed" << endl; }
};

int main() {
    MyPtr<Animal> p1(new Dog());
    MyPtr<Animal> p2(new Cat());

    p1->speak();    // 1. 출력?
    p2->speak();    // 2. 출력?
    (*p1).speak();  // 3. 출력?

    // p1, p2 scope 끝나면
    // 4. 소멸 순서와 출력은?

    return 0;
}
*/

/*
int main() {
    cout << "문제 블록 주석 해제 후 실행하세요." << endl;
    return 0;
}
*/