#include <iostream>
#include "User.h"
#include "Admin.cpp"
#include "Customer.cpp"

using namespace std;

int main() {
    int choice;

    cout << "===== Shop Management System =====\n";
    cout << "1. Admin\n";
    cout << "2. Customer\n";
    cout << "Enter choice: ";
    cin >> choice;

    User* u = nullptr;

    if (choice == 1) {
        u = new Admin("AdminUser");
    }
    else if (choice == 2) {
        u = new Customer("CustomerUser");
    }
    else {
        cout << "Invalid choice!\n";
        return 0;
    }

    u->login();
    u->displayMenu();
    u->performTask();

    delete u;

    return 0;
}