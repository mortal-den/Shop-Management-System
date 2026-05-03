#include <iostream>
#include "Product.cpp"
using namespace std;

class Bill {
private:
    float total;

public:
    Bill() {
        total = 0;
    }

    // Add product to bill
    void addToBill(Product p, int qty) {
        float price = (float)p;   // using data conversion
        total += price * qty;
    }

    // Display bill
    void displayBill() const {
        cout << "\n===== BILL =====\n";
        cout << "Total Amount: " << total << endl;
        cout << "================\n";
    }

    // Operator Overloading
    Bill operator+(Bill b) {
        Bill temp;
        temp.total = this->total + b.total;
        return temp;
    }
};