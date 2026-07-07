// Operator Overloading Test
// Holiday + Holiday
//class Type -> no + operator defined for it 
//We can overload the + operator for the Holiday class to allow adding two 
//Return type: non-pointer, non reference type(Holiday)
//Return Type: Pointer type (Holiday*)
// Return Type : Reference (Holiday&)
// operator++ () -> Pre-increment
// operator-- (int) -> Post-increment
// Date operator++ (int) -> Post-increment
// operator++ (int) -> Post-increment
//Dat temp = *this;
//++(*this)
// return temp;
//type이 3개가 있다는 걸 깜빢하면 안돼
// 그리고 copy하는데는 결과론적으로 2개의 option이 있다. 

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <memory> // include for smart pointers if needed(std::un)

using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;
        string dateStr;

    public:
        Date(int d, int m, int y) : day(d), month(m), year(y) {}
        
        void Display()
        {
            cout << day << "/" << month << "/" << year << endl;
        }
        //Unary operator overloading for pre increment
        Date& operator++()
        {
         ++day;
         return *this;
            }
        Date& operator--()
        {
           --day;
           return *this;
        }
        Date operator++(int)
        {/*
            Date temp = *this;
            ++(this->day);
            return temp;
            */
           Date Copy(day, month, year); // create a temporary copy of the 
           ++day;
           return Copy;
        }
        
        Date operator--(int)
        {
            Date temp = *this;
            --(this->day);
            return temp;
        };
        /*
        friend ostream& operator<<(ostream&, const Date& date)
        {
            cout << date.day << "/" << date.month << "/" << date.year << endl;
            return cout;
    }
            */
        // To support << operator  easy display 
        operator const char*() {
        stringstream ss;
        ss << day << "/" << month << "/" << year;
        dateStr = ss.str();
        return dateStr.c_str();
        }    
        operator int()
        {
            return day;
        }
        Date operator-(int days)
        {
            return Date(day - days, month, year);
        }
        Date operator-(const Date& other)
        {
            return Date(day-other.day, month - other.month, year - other.year);
        }
        Date operator+(int days)
        {
            return Date(day + days, month, year);
        }
        Date operator+(const Date& other)
        {
            return Date(day+other.day, month + other.month, year + other.year);
        }
        void operator+(int days)
        {
            day += days;
        }
        void operator+=(int days)
        {
            day += days;
        }
        void operator-=(int days)
        {
            day -= days;
        }
        bool operator==(const Date& other) const {
            return day == other.day && month == other.month && year == other.year;
        }
        bool operator!=(const Date& other) const {
            return !(*this == other); // Check if two Date objects are not equal
            // == 이건 primitive type operator가 아님? 
            //왜냐하면 this도 date고 여기선 other도 date니까 primitive type이 아니다?
        }
        bool operator < (const Date& other) const
        {
            if (year != other.year) return year < other.year;
            if (month != other.month) return month < other.month;
            return day < other.day;
        }
        bool operator > (const Date& other) const
        {
            return other < *this;            
        }
        bool operator <= (const Date& other) const
        {
            return !(other < *this);
        }
        bool operator >= (const Date& other) const
        {
            return !(*this < other);
        }

        Date& operator=(const Date& other)
        {
            if (this != &other)
            {
                day = other.day;
                month = other.month;
                year = other.year;
            }
            return *this;
            }
};
int main()
{
    Date Holiday(5,25,2026);
    cout <<"Original Date: ";
    Holiday.Display();
    ++Holiday; // Pre-increment
    cout << "After pre-increment: ";
    Holiday.Display();
    Holiday++; // Post-increment
    cout << "After post-increment: ";
    Holiday.Display();
    --Holiday; // Pre-decrement
    cout << "After pre-decrement: ";
    Holiday.Display();
    Holiday--; // Post-decrement
    cout << "After post-decrement: ";
    Holiday.Display();

    //cout << Holiday << endl;
    cout <<(int)Holiday << endl;
    cout << (const char*)Holiday << endl;
    
    unique_ptr<Date> datePtr = make_unique<Date>(1,1,2026);
    cout << "Date from unique_ptr" << (const char*)(*datePtr) << endl;
    cout << "Day from unique_ptr" << (int)(*datePtr) << endl;

    unique_ptr<Date> pHoliday (new Date(15,8,2026));
    cout << "Date from raw pointer" << (const char*)(*pHoliday) << endl;
    cout << "Day from raw pointer" << (int)(*pHoliday);

    Date PreviousHoliday = (Holiday-5);
    cout << "Previous Holiday: " << (const char*)PreviousHoliday << endl;
    
    return 0;
}