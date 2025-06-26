
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void speak() {
        cout << "Animal speaks" << endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat meows" << endl;
    }
};

// Derived class 3 (Diamond shape)
class Hybrid : public Dog, public Cat {
public:
    void hybridSpeak() {
        cout << "Hybrid speaks" << endl;
    }
};

int main() {
    Hybrid hybrid;

    // Accessing methods from the derived classes
    hybrid.Dog::speak();  // Calls speak() from Animal through Dog
    hybrid.Cat::speak();  // Calls speak() from Animal through Cat
    hybrid.bark();        // Calls bark() from Dog
    hybrid.meow();        // Calls meow() from Cat
    hybrid.hybridSpeak(); // Calls hybridSpeak() from Hybrid

    return 0;
}
