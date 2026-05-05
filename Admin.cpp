#include <iostream>
#include "User.h"
#include "Exception.h"
#include "Shop.cpp"

using namespace std;

class Admin : public User {
private:
    Shop* shop;

public:
    // ✅ Correct constructor
    Admin(string name, Shop* s) : User(name), shop(s) {}

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

            if (choice < 1 || choice > 3) {
                throw ShopException("Invalid menu choice");
            }

            if (choice == 1) {
                shop->addProduct();
            }
            else if (choice == 2) {
                int id;
                cout << "Enter product ID: ";
                cin >> id;
                shop->deleteProduct(id);
            }
            else if (choice == 3) {
                shop->displayProducts();
            }
        }
        catch (ShopException &e) {
            e.showError();
        }
    }
};