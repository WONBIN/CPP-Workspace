#include <iostream>
#include <map>
struct CustomlengthComapre
{
    bool operator()(const std::string& str1, const std::string& str2) const
    {
        if(str1.length() != str2.length())
        {
            return str1.length() < str2.length();
        }
            return str1 < str2;
    }
};

int main()
{
    std::map<std::string, int, CustomlengthComapre> myMap;
    
    myMap["apple"] = 5;
    myMap["banana"] = 3;
    myMap["cherry"] = 8;
    
}