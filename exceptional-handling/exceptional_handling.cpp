#include<iostream>
using namespace std;

void divide(int a,int b)
{
    if (b==0)
        throw runtime_error("Division by zero!");
    cout << "Result:" << a/b << endl;
}
int main()
{
    try
    {
        divide(10,0);
    }catch (runtime_error& e)
    {
        cout << "Caught an exception: " << e.what() << endl;
    }catch (...)
    {
        cout << "Caught an unknown exception!" << endl;
    }


}
