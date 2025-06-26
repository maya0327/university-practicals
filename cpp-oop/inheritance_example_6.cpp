#include <iostream>
using namespace std;

class Shape {
public:
    void draw() {
        cout << "Draw a shape" << endl;
    }
};

class Color {
public:
    string color;
    Color(string c) : color(c) {}
};

class Circle : public Shape {
private:
    int radius;
    Color color;
public:
    Circle(int r, string c) : radius(r), color(c) {}

    void displayInfo() {
        cout << "The radius of the circle is " << radius
             << " and the color is " << color.color << endl;
    }
};

int main() {
    Circle circle(5, "Red");
    circle.draw();
    circle.displayInfo();
}



