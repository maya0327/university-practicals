#include <iostream>
using namespace std;

class Entity {
public:
    virtual void activity() {
        cout << "Entity exists!" << endl;
    }
};

class Bird : public Entity {
public:
    void activity() override {
        cout << "Bird Flies in the sky!" << endl;
    }
};

class Fish : public Entity {
public:
    void activity() override {
        cout << "Fish Swims in water!" << endl;
    }
};

class Horse : public Entity {
public:
    void activity() override {
        cout << "Horse Runs on land!" << endl;
    }
};

int main() {
    Entity* entityPtr;

    Bird bird;
    Fish fish;
    Horse horse;


    entityPtr = &bird;
    entityPtr->activity();  

    entityPtr = &fish;
    entityPtr->activity(); 

    entityPtr = &horse;
    entityPtr->activity();  

    return 0;
}
