#include <iostream>
#include "User.h"
#include "Exception.h"
class Admin : public User {
public:
    Admin(string name = "Admin") : User(name) {}

    void login() {
        cout << "Admin " << username << " logged in.\n";
    }

    void displayMenu() {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Product\n";
        cout << "2. Delete Product\n";
        cout << "3. View Products\n";
    }

    void performTask() {
        try {
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            // Throw exception if invalid choice
            if (choice < 1 || choice > 3) {
                throw ShopException("Invalid menu choice");
            }

            if (choice == 1) {
                cout << "Adding product...\n";
            }
            else if (choice == 2) {
                cout << "Deleting product...\n";
            }
            else if (choice == 3) {
                cout << "Displaying products...\n";
            }
        }
        catch (ShopException e) {
            e.showError();
        }
    }
};