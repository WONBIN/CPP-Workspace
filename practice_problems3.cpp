// ============================================================
// 기말고사 대비 연습문제 3 (functor + custom iterator + predicate)
// ============================================================
// 풀이 방법:
//   - [OUTPUT] 문제: 주석에 예상 출력 적어보기
//   - [BLANK]  문제: _____ 채우기 (각 빈칸에 번호 표시)
// 각 문제 블록 주석 해제 후 실행 확인
// ============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


// ============================================================
// 문제 1 [OUTPUT] - functor 상태 추적 (operator() + 멤버 변수)
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
class Accumulator {
    int total;
public:
    int callCount;
    Accumulator() : total(0), callCount(0) {}
    int operator()(int x) {
        callCount++;
        total += x;
        return total;
    }
    int getTotal() { return total; }
};

int main() {
    Accumulator acc;

    cout << acc(5)  << endl;        // 1. 출력?
    cout << acc(10) << endl;        // 2. 출력?
    cout << acc(-3) << endl;        // 3. 출력?
    cout << acc.callCount  << endl; // 4. 출력?
    cout << acc.getTotal() << endl; // 5. 출력?

    return 0;
}
*/

// ============================================================
// 문제 2 [BLANK] - functor 기본 구조 (2칸)
// 조건: Doubler(x) 호출 시 x*2를 반환하는 functor
// ============================================================
/*
class Doubler {
public:
    int operator()(int x) {
        return x * 2;
    }
};

int main() {
    Doubler d;
    cout << d(5)  << endl;   // 10
    cout << d(21) << endl;   // 42
    return 0;
}

*/

// ============================================================
// 문제 3 [OUTPUT] - 커스텀 이터레이터 수동 순회 + range-based for
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
class IntBox {
    int data[5];
public:
    struct Iter {
        int* ptr;
        Iter(int* p) : ptr(p) {}
        int& operator*()  { return *ptr; }
        Iter& operator++() { ++ptr; return *this; }
        bool operator!=(const Iter& o) const { return ptr != o.ptr; }
    };
    IntBox() { for (int i = 0; i < 5; i++) data[i] = (i + 1) * 10; }
    Iter begin() { return Iter(data); }
    Iter end()   { return Iter(data + 5); }
};

int main() {
    IntBox box;
    IntBox::Iter it = box.begin();

    cout << *it << endl;        // 1. 출력?
    ++it;
    cout << *it << endl;        // 2. 출력?
    *it = 99;
    cout << *it << endl;        // 3. 출력?

    int count = 0;
    for (int x : box) count++;
    cout << count << endl;      // 4. 출력?

    int sum = 0;
    for (int& x : box) sum += x;
    cout << sum << endl;        // 5. 출력?

    return 0;
}
*/


// ============================================================
// 문제 4 [BLANK] - 커스텀 이터레이터 구현 (6칸)
// _____ 를 채워서 main이 정상 실행되게 하세요.
// ============================================================
/*
template <typename T>
class SimpleList {
    T arr[5];
    int count;
public:
    SimpleList() : count(0) {}
    void add(T val) { if (count < 5) arr[count++] = val; }

    struct Iterator {
        T* ptr;                                // (1) 멤버 변수 타입
        Iterator(T* p) : ptr(p) {}
        T& operator*()  { return *ptr; }        // (2) 반환타입, (3) 반환값
        Iterator& operator++() { ++ptr; return *this; } // (4) 반환타입, (5) 반환값
        bool operator!=(const Iterator& o) const { return ptr != o.ptr; } // (6) 연산자 이름
    };

    Iterator begin() { return Iterator(arr); }
    Iterator end()   { return Iterator(arr + count); }
};

int main() {
    SimpleList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);

    for (int x : list) cout << x << " ";   // 1 2 3
    cout << endl;
    return 0;
}
*/


// ============================================================
// 문제 5 [OUTPUT] - const& vs & in range-based for (참조 vs 상수참조)
// 예상 출력을 적고, 마지막 질문에 답하세요.
// ============================================================
/*
class NumBox {
    int data[3];
public:
    NumBox() { data[0] = 1; data[1] = 2; data[2] = 3; }
    int* begin() { return data; }
    int* end()   { return data + 3; }
};

int main() {
    NumBox box;

    for (const int& x : box) cout << x << " ";   // 1. 출력?
    cout << endl;

    for (int& x : box) x *= 10;

    for (const int& x : box) cout << x << " ";   // 2. 출력?
    cout << endl;

    //for (const int& x : box) { x = 0; }   // 3. 이 줄의 주석을 풀면? (컴파일 에러 vs 정상, 이유는?)

    return 0;
}
*/


// ============================================================
// 문제 6 [BLANK] - predicate 작성 (다단계 비교, 3칸)
// 조건: "모음으로 시작하는 단어 먼저, 그 다음 알파벳순" 정렬
// ============================================================
/*
struct VowelFirstCompare {
    bool isVowelStart(const string& s) const {
        char c = s[0];
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    bool operator()(const string& a, const string& b) const {
        bool aV = isVowelStart(a);
        bool bV = isVowelStart(b);
        if (aV != bV) return aV;          // 모음 시작 단어가 먼저
        return a < b;                    // 둘 다 같은 그룹이면 알파벳순
    }
};

int main() {
    vector<string> words = {"banana", "apple", "cherry", "egg", "date"};
    sort(words.begin(), words.end(), VowelFirstCompare());
    for (auto& w : words) cout << w << " ";
    cout << endl;
    // 예상 출력: apple egg banana cherry date
    return 0;
}

*/

// ============================================================
// 문제 7 [OUTPUT] - functor 상태 + 복사 의미론(copy) 함정
// 예상 출력을 순서대로 적어보세요.
// ============================================================
/*
class Logger {
public:
    int count;
    Logger() : count(0) {}
    void operator()(int x) {
        count++;
        cout << "[" << count << "] value=" << x << endl;
    }
};

class Nums {
    int data[4];
public:
    Nums() { for (int i = 0; i < 4; i++) data[i] = (i + 1) * 5; }
    int* begin() { return data; }
    int* end()   { return data + 4; }
};

int main() {
    Nums n;
    Logger log;

    for (int x : n) log(x);                          // 1~4. 각 줄 출력?
    cout << "total calls: " << log.count << endl;    // 5. 출력?

    Logger log2 = log;                      
    log2(100);        
    cout << "log count: "  << log.count  << endl;    // 6. 출력?
    cout << "log2 count: " << log2.count << endl;    // 7. 출력?

    return 0;
}
*/


/*
int main() {
    cout << "문제 블록 주석 해제 후 실행하세요." << endl;
    return 0;
}
*/
