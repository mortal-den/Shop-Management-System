#include <iostream>
#include "User.h"
#include "Admin.cpp"
#include "Customer.cpp"

using namespace std;

int main() {
    int choice;
    string name;

    while (true) {   // ✅ loop starts

        cout << "\n===== Shop Management System =====\n";
        cout << "1. Admin\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting system...\n";
            break;   // ✅ exit loop
        }

        User* u = nullptr;

        cout << "Enter your name: ";
        cin >> name;

        if (choice == 1) {
            u = new Admin(name);
        }
        else if (choice == 2) {
            u = new Customer(name);
        }
        else {
            cout << "Invalid choice!\n";
            continue;   // restart loop
        }

        if (u != nullptr) {
            u->login();
            u->displayMenu();
            u->performTask();
        }

        delete u;   // free memory
    }

    return 0;
}