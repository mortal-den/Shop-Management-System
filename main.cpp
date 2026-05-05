#include <iostream>
#include "User.h"
#include "Admin.cpp"
#include "Customer.cpp"
#include "Shop.cpp"

using namespace std;

int main() {
    int choice;
    string name;

    Shop globalShop;

    while (true) {

        cout << "\n===== Shop Management System =====\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        // ✅ FIX 1: safe integer input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice == 3) {
            cout << "Exiting system...\n";
            break;
        }

        cin.ignore(); // ✅ FIX 2: clear leftover newline

        cout << "Enter your name: ";
        getline(cin, name);  // ✅ FIX 3: allow full name

        User* u = nullptr;

        if (choice == 1) {
            u = new Admin(name, &globalShop);
        }
        else if (choice == 2) {
            u = new Customer(name, &globalShop);
        }
        else {
            cout << "Invalid choice!\n";
            continue;
        }

        if (u != nullptr) {
            u->login();
            u->displayMenu();
            u->performTask();
        }

        delete u;
    }

    return 0;
}