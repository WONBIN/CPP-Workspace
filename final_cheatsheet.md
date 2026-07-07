# C++ 기말고사 단권화 노트
> 시험 직전 훑기용 — 코드 패턴 + 함정 위주

---

## 1. Copy / Move 생성자·대입 연산자

### 네 가지 패턴 한눈에

```cpp
class Buffer {
    int* data;
    int  size;
public:
    // ── 1. Copy Constructor ──────────────────────────────
    Buffer(const Buffer& o) : size(o.size) {
        data = new int[size];                  // 새 메모리 할당 (deep copy!)
        for (int i = 0; i < size; i++) data[i] = o.data[i];
    }

    // ── 2. Copy Assignment Operator ──────────────────────
    Buffer& operator=(const Buffer& o) {
        if (this != &o) {                      // self-assignment 체크 필수
            delete[] data;                     // 기존 자원 해제
            size = o.size;
            data = new int[size];
            for (int i = 0; i < size; i++) data[i] = o.data[i];
        }
        return *this;                          // 반드시 *this 반환
    }

    // ── 3. Move Constructor ──────────────────────────────
    Buffer(Buffer&& o) noexcept : size(o.size), data(o.data) {
        o.data = nullptr;                      // 원본 무력화 (double-delete 방지)
        o.size = 0;
    }

    // ── 4. Move Assignment Operator ──────────────────────
    Buffer& operator=(Buffer&& o) noexcept {
        if (this != &o) {
            delete[] data;                     // 기존 자원 해제
            data = o.data;  size = o.size;     // 소유권 이전
            o.data = nullptr; o.size = 0;      // 원본 무력화
        }
        return *this;
    }
};
```

### 언제 각각 호출되나

| 상황 | 호출되는 것 |
|------|------------|
| `Buffer b2 = b1;` | **Copy Constructor** (b2가 처음 탄생) |
| `b2 = b1;` (b2 이미 존재) | **Copy Assignment** |
| `Buffer b2 = std::move(b1);` | **Move Constructor** |
| `b2 = std::move(b1);` (b2 이미 존재) | **Move Assignment** |
| 함수에 by-value 파라미터 | **Copy Constructor** |
| 함수에서 by-value 반환 | **Copy Constructor** (컴파일러 최적화로 생략될 수 있음) |

### ❗ 핵심 함정
```cpp
Box b2 = b1;        // Copy Constructor   ← 초기화(=탄생) 시점이니까
Box b2;  b2 = b1;   // Default + Copy Assignment  ← 두 단계
```

### Shallow copy 문제
```cpp
// 복사 생성자에서 data = o.data; 만 하면 (shallow copy):
// → b1과 b2가 같은 메모리를 가리킴
// → b2.set(0, 99) 하면 b1도 바뀜
// → 소멸 시 같은 메모리를 두 번 delete → crash
```

---

## 2. Operator Overloading

### operator<< (스트림 출력) — friend 함수

```cpp
class Point {
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}

    // 반드시 friend — 왼쪽이 cout(ostream)이어야 하기 때문
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;   // ← 연쇄 출력(cout << a << b)을 위해 os 반환 필수
    }
};
// cout << p1 << " and " << p2 << endl;  → 정상 동작
```
> **멤버 함수로 못 만드는 이유**: 멤버 함수면 왼쪽이 Point여야 하는데, `cout << p`에서 왼쪽은 cout(ostream)임.  
> **void 반환 안 되는 이유**: `cout << a << b`는 `(cout << a) << b` — 첫 번째 결과가 ostream&여야 두 번째 `<<`를 이어 적용할 수 있음.

### prefix / postfix ++

```cpp
class Counter {
    int val;
public:
    Counter(int v) : val(v) {}

    Counter& operator++()    { ++val; return *this; }   // prefix:  ++c  → 증가 후 자신 참조 반환
    Counter  operator++(int) { Counter tmp(val); ++val; return tmp; }  // postfix: c++ → 증가 전 복사본 반환
};

Counter a(5);
Counter b = a++;   // b=5, a=6  (postfix: 먼저 복사, 그 다음 증가)
Counter c = ++a;   // c=7, a=7  (prefix: 증가 후 자신)
```

### operator< 하나에서 나머지 파생

```cpp
bool operator>(const T& o)  const { return o < *this; }       // "상대가 나보다 작다" = 내가 크다
bool operator<=(const T& o) const { return !(o < *this); }    // 크지 않다
bool operator>=(const T& o) const { return !(*this < o); }    // 작지 않다
bool operator!=(const T& o) const { return !(*this == o); }   // 같지 않다
```

### 캐스팅 연산자

```cpp
class Temperature {
    double celsius;
public:
    operator double() const { return celsius; }  // (double)t 또는 암묵적 변환 허용
};
// double avg = (t1 + t2) / 2;  → operator double()로 암묵적 변환 후 double 연산
```

### Smart Pointer: operator* vs operator->

```cpp
template<typename T>
class SmartPtr {
    T* ptr;
public:
    T& operator*()  { return *ptr; }   // *sp → 객체 자체 (역참조), T& 반환
    T* operator->() { return ptr; }    // sp->func() → 포인터 반환, 컴파일러가 -> 한 번 더 적용
};
// operator*: dereference니까 *ptr, 객체 자체니까 T&
// operator->: 포인터니까 ptr 그대로, 타입도 T*
```

---

## 3. Lambda 함수

### 기본 구조

```cpp
[캡처](파라미터) { 본문 }
[캡처](파라미터) -> 반환타입 { 본문 }
```

### 캡처 방식 — 핵심 함정

```cpp
int val = 10;
auto f1 = [val](int x)  { return x + val; };   // 값 캡처: 생성 시점(10) 박제, 이후 변화 무관
auto f2 = [&val](int x) { val += x; return val; }; // 참조 캡처: 항상 최신값 반영

val = 20;
f1(5);  // → 10 + 5 = 15  (val이 20으로 바뀌었어도 f1은 10을 들고 있음)
f2(5);  // → val = 20+5 = 25  (실시간 반영)
```

> `[val]` = 사진처럼 찍어서 박제 → 이후 원본 변해도 람다 내부는 그대로  
> `[&val]` = 실시간 창문 → 항상 현재 값

### STL 알고리즘과 함께

```cpp
vector<int> v = {3,1,4,1,5,9};

// 오름차순 정렬
sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

// 내림차순 정렬
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

// 조건 만족하는 원소 개수
int cnt = count_if(v.begin(), v.end(), [](int x) { return x > 4; });  // cnt = 2

// 각 원소에 적용
for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
```

---

## 4. Functor (함수 객체)

### 정의

`operator()`를 정의해서 `()`로 호출 가능하게 만든 객체. **함수와 달리 상태(멤버 변수)를 호출 사이에 유지**.

```cpp
class Accumulator {
    int total = 0;
public:
    void operator()(int x) { total += x; }
    int getTotal() const { return total; }
};

Accumulator acc;
acc(10); acc(20); acc(30);
cout << acc.getTotal();  // 60 — 호출 사이에 total이 누적됨
```

### for_each + functor 함정 — 값으로 전달

```cpp
vector<int> data = {10, 20, 30};  // 순회 대상 벡터
Tracker t1;               // t1.seen = {}
for (int x : data) t1(x); // data 원소를 하나씩 꺼내 t1(x) 호출 → t1.seen = {10,20,30}

// for_each는 functor를 "값으로" 전달 → t1의 복사본이 만들어짐
// 복사 시점에 t1.seen = {10,20,30}이므로 복사본도 그 상태로 출발
for_each(data.begin(), data.end(), t1);
// 출력: size=4, size=5, size=6 (복사본의 작업)
// 원본 t1.seen은 여전히 {10,20,30} — for_each가 끝나면 복사본 소멸

cout << t1.total();  // 3 (원본 불변)
```

> **STL 알고리즘이 functor를 값으로 받는 이유**: 함수포인터·functor·람다를 균일하게 받기 위한 템플릿 설계.  
> **Iterator는 가벼워서** 복사돼도 무관하지만, **상태 가진 functor는** 복사 시점/원본 불변이 함정.

---

## 5. Predicate (비교 조건자)

### 기본 원리

```cpp
// sort의 comparator: "a가 b보다 앞에 와야 하면 true"
struct AscCompare {
    bool operator()(int a, int b) const {
        return a < b;   // a가 작으면 a가 앞 → 오름차순
    }
};
// return a > b → 내림차순
```

### 다단계 비교

```cpp
struct AgeThenName {
    bool operator()(const Person& p1, const Person& p2) const {
        if (p1.age != p2.age)
            return p1.age < p2.age;    // 나이 오름차순
        return p1.name < p2.name;      // 나이 같으면 이름 오름차순
    }
};
```

### VowelFirst 패턴 — 왜 `return aV`인가

```cpp
bool operator()(const string& a, const string& b) const {
    bool aV = (a[0]=='a'||a[0]=='e'||a[0]=='i'||a[0]=='o'||a[0]=='u');
    bool bV = (b[0]=='a'||b[0]=='e'||b[0]=='i'||b[0]=='o'||b[0]=='u');
    if (aV != bV) return aV;   // aV=true면 a가 모음 → a가 앞 → true 반환
    return a < b;
}
// if (aV != bV): 정확히 하나만 모음인 상황
// "a가 앞에 와야 하는가?" = "a가 모음인가?" = aV
// bV를 반환하면 "b가 모음이냐"를 반환하는 것 → 주어(subject)가 다름
```

---

## 6. STL 알고리즘 / Iterator / Range-based for

### 알고리즘 읽는 공통 골격

```cpp
sort      (v.begin(), v.end(), comparator);  // 범위 정렬
for_each  (v.begin(), v.end(), callable);    // 각 원소에 callable 적용
count_if  (v.begin(), v.end(), predicate);   // 조건 만족 개수
```
→ **(범위시작, 범위끝, 적용할 대상)** 3등분으로 항상 읽기.

### begin() / end() — 인덱스가 아님

```cpp
// begin(): 첫 번째 원소를 가리키는 iterator
// end():   마지막 원소 바로 다음 위치 (경계 표시, 실제 원소 아님)
// [begin, end) 반열린구간이 STL 관례
```

### 커스텀 iterator 구조

```cpp
struct Iter {
    char* ptr;
    Iter(char* p) : ptr(p) {}
    char& operator*()  { return *ptr; }         // 역참조: 가리키는 원소 반환, T& 타입
    Iter& operator++() { ++ptr; return *this; } // 다음 위치로, Iter& 반환
    bool operator!=(const Iter& o) const { return ptr != o.ptr; }
};
```

### ❗ 스코프 함정: 중첩 타입

```cpp
class CharBox {
public:
    struct Iter { ... };   // 진짜 이름은 CharBox::Iter
};

// main에서:
Iter it = box.begin();          // ❌ 컴파일 에러: Iter를 모름
CharBox::Iter it = box.begin(); // ✅ 스코프 명시
auto it = box.begin();          // ✅ auto로 추론
```

### Range-based for 읽는 법

```cpp
for (int n : nums) { ... }   // nums 각 원소를 복사해서 n에 담음 (원본 불변)
for (int& n : nums) { ... }  // 참조로 받음 → n 수정 시 원본도 수정됨

// 내부적으로 이렇게 펼쳐짐:
for (auto it = nums.begin(); it != nums.end(); ++it) {
    int n = *it;
    ...
}
```

---

## 7. 상속 + Virtual + 다형성

### 생성자·소멸자 호출 순서

```cpp
// 생성: Base → Derived 순 (베이스 먼저 완성)
// 소멸: Derived → Base 순 (역방향)
// 생성자는 절대 virtual 불가
```

### Virtual Destructor 체인 — 핵심 트랩

```cpp
class Base {
public:
    virtual ~Base() { cout << "~Base" << endl; }  // virtual 필수!
};
class Derived : public Base {
public:
    ~Derived() { cout << "~Derived" << endl; }
};

Base* p = new Derived();
delete p;
// virtual 있음 → ~Derived() 먼저, ~Base() 다음 (올바른 체인)
// virtual 없음 → ~Base()만 호출, ~Derived() 스킵 → 자원 누수!
```

| 상황 | Virtual 있음 | Virtual 없음 |
|------|-------------|-------------|
| 스택 객체 `Derived d;` | 전체 체인 ✅ | 전체 체인 ✅ |
| `Base* p = new Derived(); delete p;` | 전체 체인 ✅ | Base만 ❌ |

### 정적 바인딩 vs 동적 바인딩

```cpp
class Base {
public:
    void hello() { cout << "Base::hello" << endl; }          // non-virtual → 정적 바인딩
    virtual void greet() { cout << "Base::greet" << endl; }  // virtual → 동적 바인딩
};
class Child : public Base {
public:
    void hello() { cout << "Child::hello" << endl; }
    void greet() override { cout << "Child::greet" << endl; }
};

Base* bp = new Child();
bp->hello();   // "Base::hello"  → 정적 타입(Base)만 보고 컴파일타임에 결정
bp->greet();   // "Child::greet" → 런타임에 실제 객체(Child) 확인 후 결정
```

### Method Hiding vs Override

```cpp
class Base {
public:
    void hello()      { ... }  // (A)
    void hello(int x) { ... }  // (B)
};
class Child : public Base {
public:
    void hello() { ... }       // (A)만 정의해도 (B)까지 통째로 가려짐!
};

Child c;
c.hello();          // OK → Child::hello()
c.hello(42);        // ❌ 컴파일 에러 — Child 스코프에서 hello 찾았는데 int 버전 없음
c.Base::hello(42);  // ✅ 스코프 명시로 해결
```

> **Hiding**: 이름(name) 단위로 가려짐, 시그니처 무관, 컴파일타임  
> **Override**: 같은 시그니처 + virtual → vtable 교체, 런타임 dispatch

### 다형성 + virtual 함수 패턴

```cpp
void MakeFishSwim(Fish& fish) {  // Fish& 또는 Fish*로 받아야 다형성 작동
    fish.swim();                  // 실제 객체 타입에 따라 동적 dispatch
}

Fish* arr[2] = { new Tuna(), new Carp() };
for (int i = 0; i < 2; i++) arr[i]->swim();   // 각자 override된 swim() 호출
```

---

## 8. 추상 클래스 (Abstract Base Class)

```cpp
class Shape {
public:
    virtual double area() = 0;   // pure virtual → Shape는 인스턴스화 불가
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() override { return 3.14 * r * r; }  // 반드시 override해야 인스턴스화 가능
};

// Shape s;          // ❌ 컴파일 에러: 추상 클래스는 직접 생성 불가
Shape* sp = new Circle(2.0);  // ✅ 포인터는 OK
```

> `= 0` → pure virtual → 클래스가 추상 클래스가 됨 → 직접 인스턴스화 불가  
> 파생 클래스가 pure virtual을 override 안 하면 그 파생 클래스도 추상 클래스

---

## 9. Private / Protected 상속

```cpp
class Engine { public: void start(); void stop(); };

class Car : private Engine {  // Engine의 모든 멤버가 Car 내부에서 private
public:
    void drive() {
        start();   // ✅ Car 멤버 함수 "내부"에서는 호출 가능 (집 안의 방)
        stop();
    }
};

Car c;
c.drive();    // ✅
c.start();    // ❌ 컴파일 에러: 외부에서 start() 접근 불가 (private 상속)
```

> **집/방 비유**: private 상속 = 상속받은 기능을 집 내부 방으로 격리. 집 내부(멤버 함수)에서는 자유롭게 쓸 수 있지만, 외부인(main)은 접근 불가.

### ❗ 파생 클래스 체인에서의 함정 — SuperCar 예제

```cpp
class Engine { public: void start(); void stop(); };

class Car : private Engine {       // start/stop → Car 내부에서 private
public:
    void drive() { start(); stop(); }  // ✅ Car 멤버 함수: OK
};

class SuperCar : public Car {
public:
    void sc() {
        start();   // ❌ 컴파일 에러
        stop();    // ❌ 컴파일 에러
    }
};
```

**왜 에러?** `Car : private Engine` → start()/stop()은 **Car의 private 멤버**가 됨.
private = Car 자신의 멤버 함수만 접근 가능. Car를 상속받은 SuperCar도 접근 불가.

| 상속 방식 | Car 내부 | SuperCar 내부 | 외부(main) |
|-----------|---------|--------------|-----------|
| `private Engine` | ✅ | ❌ | ❌ |
| `protected Engine` | ✅ | ✅ | ❌ |
| `public Engine` | ✅ | ✅ | ✅ |

> **기억법**: private = "나만 쓸게", protected = "자식한테는 줄게", public = "다 써도 돼"

---

## 10. 다중 상속 + Diamond + Virtual 상속

```cpp
class Animal { public: Animal() { cout << "Animal()\n"; } };
class Mammal  : public virtual Animal { public: Mammal()  { cout << "Mammal()\n";  } };
class Bird    : public virtual Animal { public: Bird()    { cout << "Bird()\n";    } };
class Platypus : public Mammal, public Bird {
public: Platypus() { cout << "Platypus()\n"; }
};

Platypus p;
// 출력: Animal() → Mammal() → Bird() → Platypus()
// virtual 상속: Animal이 딱 1번만 생성됨
```

> **Diamond 문제**: Mammal, Bird 둘 다 Animal을 일반 상속하면 Platypus 안에 Animal이 2개  
> **virtual 상속**: `virtual` 붙이면 Animal이 1개로 공유됨   
> **생성 순서**: virtual base → 왼쪽 상속 → 오른쪽 상속 → 자기 자신 

---

## 11. 함수 포인터

```cpp
void triple(int& x) { x *= 3; }

void (*fp)(int&);    // int&를 받고 void를 반환하는 함수를 가리키는 포인터
fp = triple;         // 함수 이름 = 그 함수의 시작 주소
fp(a);               // triple(a)와 동일

void (*ops[3])(int&) = {triple, ...};  // 함수 포인터 배열
for (int i = 0; i < 3; i++) ops[i](a);
```

---

## 12. Implicit / Explicit 변환 생성자

```cpp
class Meter {
public:
    Meter(double v) : value(v) {}   // implicit 변환 허용
    // explicit Meter(double v) ...  // explicit: 명시적 생성만 허용
};

void printMeter(Meter m) { ... }

Meter m1 = 3.5;    // (a) implicit 허용 시 OK, explicit 시 ❌
printMeter(5.0);   // (b) implicit 허용 시 OK (double → Meter 암묵적 변환), explicit 시 ❌
Meter m2(2.0);     // (c) 항상 OK — 이건 암묵적 변환이 아니라 직접 생성자 호출
```

> `explicit` = 암묵적 변환 차단, 직접 생성(`Meter m(2.0)`)은 여전히 허용  
> (a)(b)는 `double → Meter`로 암묵적 변환 발생 → explicit 시 에러  
> (c)는 변환이 아니라 생성자 직접 호출 → explicit 있어도 에러 아님

---

## 13. 빈칸 채우기 핵심 패턴 정리

```cpp
// ① operator<< 시그니처
friend ostream& operator<<(ostream& os, const MyClass& obj) {
    os << obj.data;
    return os;          // os 반환 (연쇄 출력 위해)
}

// ② Predicate — 오름차순
bool operator()(const T& a, const T& b) const { return a < b; }
// 내림차순
bool operator()(const T& a, const T& b) const { return a > b; }

// ③ Smart Pointer
T& operator*()  { return *ptr; }   // 역참조 → 객체, T&
T* operator->() { return ptr; }    // 포인터 반환, T*

// ④ Iterator operator*
T& operator*() { return *ptr; }    // *it → 가리키는 데이터, T&
// Iterator operator++
Iterator& operator++() { ++ptr; return *this; }   // *this 반환 (Iterator 자신)

// ⑤ Pure virtual
virtual void func() = 0;           // = 0 → pure virtual

// ⑥ 람다 값 캡처 / 참조 캡처
[x]    // 값 캡처: 생성 시점 박제
[&x]   // 참조 캡처: 실시간 반영
[=]    // 모든 변수 값 캡처
[&]    // 모든 변수 참조 캡처

// ⑦ Derived 비교연산자 도출
bool operator>(const T& o)  const { return o < *this; }
bool operator<=(const T& o) const { return !(o < *this); }
bool operator>=(const T& o) const { return !(*this < o); }
bool operator!=(const T& o) const { return !(*this == o); }
```

---

## 14. 오늘 반복적으로 헷갈린 것들 — 최종 정리

| 질문 | 답 |
|------|-----|
| `Box b2 = b1;` 이거 copy ctor야 assignment야? | Copy Constructor (탄생 시점) |
| `for_each`에서 functor 원본이 바뀌나? | 아니오. 복사본이 작업하고 사라짐 |
| `[threshold]` 람다, threshold 바뀌면 반영되나? | 아니오. 생성 시점 값으로 박제 |
| `operator->()` 반환 타입이 왜 T*? | 컴파일러가 -> 한 번 더 적용해주기 때문 |
| `operator*()` 반환 타입이 왜 T&? | 역참조 = 객체 자체를 반환해야 해서 |
| `return aV`가 왜 맞고 `return bV`가 왜 틀려? | "a가 앞에 와야 하는가" = "a가 모음인가" = aV |
| non-virtual 소멸자, Base*로 delete하면? | Derived 소멸자 스킵 → 자원 누수 |
| 스택 객체는 virtual 없어도 full 체인? | 맞음. 정적 타입 알기 때문 |
| `c.hello(42)` Child에서 컴파일 에러? | method hiding: 이름 단위로 가려져서 |
| `CharBox::Iter`를 main에서 `Iter`로 쓰면? | 컴파일 에러: 스코프 명시 필요 |
| `for_each`가 값으로 받는 이유? | 다양한 callable 타입 균일 처리 + 인라인 최적화 |
| `explicit` 있어도 `Meter m(2.0)` 되는 이유? | 암묵적 변환 아니라 직접 생성자 호출 |

---

*시험 잘 봐 — 지금까지 다 다뤘던 내용이야, 자신 있게 들어가*
