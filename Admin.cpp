#include <iostream>
#include "User.h"
#include "Exception.h"
#include "Shop.cpp"   // ✅ include Shop

using namespace std;

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
        static Shop shop;   // ✅ persistent shop object

        try {
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            // Validate choice
            if (choice < 1 || choice > 3) {
                throw ShopException("Invalid menu choice");
            }

            if (choice == 1) {
                shop.addProduct();   // ✅ real function
            }
            else if (choice == 2) {
                int id;
                cout << "Enter product ID to delete: ";
                cin >> id;
                shop.deleteProduct(id);   // ✅ real function
            }
            else if (choice == 3) {
                shop.displayProducts();   // ✅ real function
            }
        }
        catch (ShopException &e) {   // ✅ better catch
            e.showError();
        }
    }
};