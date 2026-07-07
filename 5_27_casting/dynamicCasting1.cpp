// Inheritance Relationships and Dynamic Casting
// This program demonstrates the use of dynamic_cast in C++ to safely down cast pointersin an inheritance. --> very important keyword is Dynamic_cast->Inheritane(Polymorphism) with virtual method 
// In this example We have a base class 'Base' and a derived class 'Derived'. We will create an 
// The dynamic_cast operator is used to perform safe 
// Note: this program requires RTTI to be enabled, which is typically 

#include <iostream>
using namespace std;

class Animal
{
    public:
        virtual void speak()
        {
            cout << "Animal speaks" << endl;
        }
        virtual ~Animal() {} // virtual destructor for proper cleanup
};

class Dog : public Animal
{
    public:
        void speak() override 
        { // Override the speak function
            cout << "Dog barks" << endl;
        }
        void wagTail()
        {
            cout << "Dog wags its tail" << endl;
        }
};

class Cat : public Animal
{
    public:
        void speak() override
        {
            cout << "Cat meows" << endl;
        }
        void purr()
        {
            cout << "Cat purrs" << endl;
        }
};

void makeAnimalSpeak(Animal* animal)
{
    animal->speak(); // Call the speak function, which will be resolved at runtime
    //Use dynamic_cast to check if the animal is dog
    if(Dog* dog = dynamic_cast<Dog*>(animal))
    {
        dog->wagTail();
    }
    else if (Cat* cat = dynamic_cast<Cat*>(animal))
    {
        cat->purr();
    }
    else
    {
        cout << "Unknown animal type" << endl;
    }
}
// start from derived class go back to base class 
// call the instance of 

int main()
{
    Animal* animalPtr = new Dog();
    animalPtr->speak();
    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);
    if (dogPtr)
    {
        dogPtr->wagTail();
    }
    else
    {
        cout << "Failed to downcast to Dog" <<endl;
    }

    //Attempt to downcast the Animal pointer to a cat pointer using dynamic_cast
    Cat* catPtr = dynamic_cast<Cat*>(animalPtr);
    if (catPtr)
    {
        catPtr->purr();
    }
    else
    {
        cout << "Failed to downcast to Cat" << endl;
    }

    return 0;
}