#include <iostream>
using namespace std;


class Fish {
protected:
    bool FreshWaterFish;
public:
    Fish(bool isFresh) : FreshWaterFish(isFresh) {}
    void swim() {
        cout << (FreshWaterFish ? "Fresh" : "Salt") << endl;
    }
};

class Tuna : public Fish {
public:
    Tuna() : Fish(false) {}
    void swim() {
        cout << "Tuna" << endl;
    }
};

int main() {
    Tuna t;
    Fish* p = &t;

    t.swim();     // ①
    p->swim();    // ②
    p->Fish::swim(); // ③
}