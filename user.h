#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

// Abstract Base Class
class User {
protected:
    string username;

public:
    // Constructor
    User(string name = "Guest") {
        username = name;
    }

    // Pure Virtual Functions (Mandatory)
    virtual void login() = 0;
    virtual void displayMenu() = 0;
    virtual void performTask() = 0;

    // Virtual Destructor
    virtual ~User() {
        cout << "User destroyed\n";
    }
};

#endif