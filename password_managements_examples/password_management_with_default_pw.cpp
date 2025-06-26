#include<iostream>
#include<string>

using namespace std;

class UserAuth {
private:
    string u;
    string pw;

public:
    UserAuth() : u("guest"), pw("guest123") {}

    UserAuth(const string& user, const string& pass) : u(user), pw(pass) {}

    bool login(const string& user, const string& pass) {
        return (u == user && pw == pass);
    }
};

int main() {
    UserAuth user("admin", "admin123");

    string inputUser, inputPass;
    cout << "Enter u: ";
    cin >> inputUser;
    cout << "Enter password: ";
    cin >> inputPass;

    cout << (user.login(inputUser, inputPass) ? "Login Successful!" : "Login Failed!") << endl;

    return 0;
}
