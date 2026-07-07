// We create a class that prohibits instantiation on the Stack
#include <iostream>
using namespace std;

class MongoDB 
{
    private:
         ~MongoDB();
    public:
       static void DestroyInstance(MongoDB* db)
       {
           delete db; // This will call the private destructor
       }
};
int main()
{
    //MongoDB db; // error: destructor is private within this context
    MongoDB *myDB = new MongoDB(); // This is fine, because we are creating an instance on the Heap, and the destructor will be called when we delete the pointer. However, we should remember to delete the pointer to avoid memory leaks.
    //delete myDB; // Destructor is private -> solution : static...
    MongoDB::DestroyInstance(myDB); // This will call the private destructor through the static method, and it will delete the instance properly.
}