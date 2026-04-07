#include "User.h"
#include "Exception.h"   // ✅ add this
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
        try {
            int quantity;
            cout << "Enter quantity to purchase: ";
            cin >> quantity;

            // Throw exception if invalid input
            if (quantity < 0) {
                throw ShopException("Quantity cannot be negative");
            }

            cout << "Purchase successful for quantity: " << quantity << endl;
        }
        catch (ShopException e) {
            e.showError();
        }
    }
};