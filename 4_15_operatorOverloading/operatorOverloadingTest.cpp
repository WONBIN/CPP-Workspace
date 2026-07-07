// struct 
#include <iostream>
#include <string>

using namespace std;

struct Point
{
    int x,y;

/*
    friend ostream& operator<<(ostream& os, const Point& p);

    {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
    */

//function overloading이란 개념
/*
ostream& operator<<(ostream& os, const Point& p)
    {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}
*/
Point(int x=0, int y=0) : x(x), y(y) {}
Point operator+(const Point& other) const 
{
    return Point(x + other.x, y + other.y);
}
//Convert the point to  a string
 operator const char*() const
 {
   /* static char buffer[50];
    snprintf(buffer, sizeof(buffer),"(%d,%d)",x,y);
    return buffer;
*/
 return ("(" + to_string(x) + "," + to_string(y) + ")").c_str();
 }
 
};
int main()
{
    Point p = {3,4};
    cout << "Point: " << p << endl;
    Point p1 (1,3);
    Point p2 (2,5);
    Point p3 = p1 + p2;
    cout << "Point: " << p3.x << "," << p3.y <<  endl;

    return 0;
}