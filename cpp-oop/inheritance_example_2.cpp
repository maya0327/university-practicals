#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "This animal eats food to survive." << endl;
    }

    void sleep() {
        cout << "This animal sleeps to rest." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Woof! Woof!" << endl;
    }

    void guard() {
        cout << "Dog is guarding the house." << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "Meow! Meow!" << endl;
    }

    void scratch() {
        cout << "Cat is scratching furniture." << endl;
    }
};

class Cow : public Animal {
public:
    void moo() {
        cout << "Moo! Moo!" << endl;
    }

    void giveMilk() {
        cout << "Cow provides milk for humans." << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;
    Cow cow;

    cout << "\nDog Features:" << endl;
    dog.eat();
    dog.sleep();
    dog.bark();
    dog.guard();

    cout << "\nCat Features:" << endl;
    cat.eat();
    cat.sleep();
    cat.meow();
    cat.scratch();

    cout << "\nCow Features:" << endl;
    cow.eat();
    cow.sleep();
    cow.moo();
    cow.giveMilk();

    return 0;
}

