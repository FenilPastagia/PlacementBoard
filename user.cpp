#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

// Shared helper function to mask passwords across all modules
inline string getMaskedPassword() {
    string pass = "";
    char ch;
    while ((ch = _getch()) != 13) { // 13 is Enter key
        if (ch == 8) { // 8 is Backspace key
            if (pass.length() > 0) {
                pass.pop_back();
                cout << "\b \b";
            }
        } else {
            pass.push_back(ch);
            cout << "*";
        }
    }
    cout << endl;
    return pass;
}

// BASE CLASS (Demonstrates Inheritance)
class User {
protected:
    string email;
    string password;

public:
    virtual bool login() {
        return false;
    }
};