#include <iostream>
#include "User.h"
#include "Exception.h"
#include "Shop.cpp"   // ✅ connect Shop

using namespace std;

class Customer : public User {
public:
    Customer(string name = "Customer") : User(name) {}

    void login() {
        cout << "Customer " << username << " logged in.\n";
    }

    void displayMenu() {
        cout << "\n--- Customer Menu ---\n";
        cout << "1. View Products\n";
        cout << "2. Buy Product\n";
    }

    void performTask() {
        static Shop shop;   // ✅ shared shop

        try {
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice < 1 || choice > 2) {
                throw ShopException("Invalid menu choice");
            }

            if (choice == 1) {
                shop.displayProducts();   // ✅ view products
            }
            else if (choice == 2) {
                int id, qty;

                cout << "Enter product ID: ";
                cin >> id;

                cout << "Enter quantity: ";
                cin >> qty;

                if (qty < 0) {
                    throw ShopException("Quantity cannot be negative");
                }

                shop.buyProduct(id, qty);   // ✅ buy product
            }
        }
        catch (ShopException &e) {   // ✅ better catch
            e.showError();
        }
    }
};