#include <iostream>
using namespace std;

class Dessert {
public:
    void sweetTaste() {
        cout << "This dessert has a sweet taste." << endl;
    }

    void calories() {
        cout << "This dessert contains calories for energy." << endl;
    }
};

class IceCream : public Dessert {
public:
    void melt() {
        cout << "The ice cream is melting in warm temperature." << endl;
    }

    void scoop() {
        cout << "Scooping the ice cream into a bowl." << endl;
    }
};

class Cookie : public Dessert {
public:
    void crunch() {
        cout << "The cookie is crunchy and tasty!" << endl;
    }

    void bake() {
        cout << "The cookie is baked at a high temperature." << endl;
    }
};
class Cake : public Dessert {
public:
    void slice() {
        cout << "Slicing the cake into pieces." << endl;
    }

    void frost() {
        cout << "Adding frosting to the cake." << endl;
    }
};

int main() {
    IceCream iceCream;
    Cookie cookie;
    Cake cake;

    cout << "\nIce Cream Features:" << endl;
    iceCream.sweetTaste();
    iceCream.calories();
    iceCream.melt();
    iceCream.scoop();

    cout << "\nCookie Features:" << endl;
    cookie.sweetTaste();
    cookie.calories();
    cookie.crunch();
    cookie.bake();

    cout << "\nCake Features:" << endl;
    cake.sweetTaste();
    cake.calories();
    cake.slice();
    cake.frost();

    return 0;
}
