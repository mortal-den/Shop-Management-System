#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
using namespace std;

// Custom Exception Class
class ShopException {
    string message;

public:
    // Constructor
    ShopException(string msg) {
        message = msg;
    }

    // Function to display error
    void showError() const {
        cout << "Error: " << message << endl;
    }
};

#endif