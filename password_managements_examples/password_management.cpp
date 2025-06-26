#include <iostream>
#include <string>

using namespace std;

class UserAuth {
private:
    string u;
    string pw;

public:
    UserAuth() : u("nfsu"), pw("nfsu123") {}
    UserAuth(const string& user, const string& pass) : u(user), pw(pass) {}
    UserAuth(const UserAuth& source) : u(source.u), pw("nfsu123") {}

    bool login(const string& user, const string& pass) {
        return u == user && pw == pass;
    }

    ~UserAuth() {
        cout << "User " << u << " has been logged out securely.\n";
    }
};

int main() {
    UserAuth user1("abc", "abc123"), user2(user1);

    string inU, inP;
    cout << "Enter username: ";
    cin >> inU;
    cout << "Enter password: ";
    cin >> inP;

    cout << (user1.login(inU, inP) ? "Login Successful!" : "Login Failed!") << endl;

    return 0;
}

