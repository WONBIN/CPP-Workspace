#include <iostream>

using namespace std;

namespace MS
{
        double OSVersion = 11;
        string OSName("Windows"); // string을 쓰고 싶으면 we need another namespace

}
namespace Apple
{
     double OSVersion = 26.3;
     string OSName("Tahoe");
}

int main()
{
    using namespace Apple; // Apple namespace를 사용하겠다.
   cout << "Hello, World!!" << endl;
   cout << "Apple OS Version: " << OSVersion << endl;
   cout << "Apple OS Name: " << OSName << endl;
   cout << "OS Version: " << MS::OSVersion << endl;
   cout << "OS Name: " << MS::OSName << endl;
   cerr << "This is Not Error!!" << endl;
    return 0;

}