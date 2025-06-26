#include<iostream>
using namespace std;

class B {
public:
    void showB() {cout<<"B";}
};
class D: public B
{
public:
    void showD (){
    cout << "D";
    }
};

int main ()
{
    B* bPtr;
    B b;
    D d;

    bPtr = &b;
    bPtr->showB();
    cout<< endl;

    bPtr = &d;
    bPtr->showD();
}
