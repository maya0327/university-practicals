#include <iostream>
using namespace std;

class Vehicle {
public:
    void wheels() {
        cout << "This vehicle has wheels to move." << endl;
    }

    void accelerate() {
        cout << "The vehicle is accelerating..." << endl;
    }
};

class Bike : public Vehicle {
public:
    void gear() {
        cout << "The bike has a gear system." << endl;
    }

    void clutch() {
        cout << "The bike uses a clutch for gear shifting." << endl;
    }
};

class Scooty : public Vehicle {
public:
    void brake() {
        cout << "The scooty is applying brakes." << endl;
    }
};
class Scooter : public Vehicle {
public:
    void oldParts() {
        cout << "This scooter has old mechanical parts." << endl;
    }
};

int main() {
    Bike bike;
    Scooty scooty;
    Scooter scooter;

    cout << "\nBike Features:" << endl;
    bike.wheels();
    bike.accelerate();
    bike.gear();
    bike.clutch();

    cout << "\nScooty Features:" << endl;
    scooty.wheels();
    scooty.accelerate();
    scooty.brake();

    cout << "\nScooter Features:" << endl;
    scooter.wheels();
    scooter.accelerate();
    scooter.oldParts();

    return 0;
}


