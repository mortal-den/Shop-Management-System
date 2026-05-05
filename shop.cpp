#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include "Product.cpp"
#include "Bill.cpp"

using namespace std;

class Shop {
private:
    Product* products;   // dynamic array
    int count;           // current number of products
    int capacity;        // max capacity

public:
    // Constructor
    Shop(int size = 10) {
        capacity = size;
        count = 0;
        products = new Product[capacity];
    }

    // Add Product
    void addProduct() {
        if (count >= capacity) {
            cout << "Shop is full!\n";
            return;
        }

        cout << "\nEnter Product Details:\n";
        products[count].input();
        count++;

        cout << "Product added successfully!\n";
    }

    // Display Products
    void displayProducts() const {
        if (count == 0) {
            cout << "No products available.\n";
            return;
        }

        cout << "\n--- Product List ---\n";
        for (int i = 0; i < count; i++) {
            products[i].display();
            cout << "---------------------\n";
        }
    }

    // Delete Product (by ID)
    void deleteProduct(int id) {
        bool found = false;

        for (int i = 0; i < count; i++) {
            if (products[i].getId() == id) {   // ✅ correct logic
                found = true;

                for (int j = i; j < count - 1; j++) {
                    products[j] = products[j + 1];
                }

                count--;
                cout << "Product deleted successfully!\n";
                break;
            }
        }

        if (!found) {
            cout << "Product not found!\n";
        }
    }

    // Buy Product + Billing
    void buyProduct(int id, int qty) {
        if (qty <= 0) {
            cout << "Invalid quantity!\n";
            return;
        }

        bool found = false;

        for (int i = 0; i < count; i++) {
            if (products[i].getId() == id) {   // ✅ correct ID matching
                found = true;

                if (products[i].getQuantity() >= qty) {

                    Bill bill;   // create bill
                    bill.addToBill(products[i], qty);

                    products[i].setQuantity(products[i].getQuantity() - qty);

                    cout << "Purchase successful!\n";
                    bill.displayBill();   // show bill

                } else {
                    cout << "Not enough stock!\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Product not found!\n";
        }
    }

    // Destructor
    ~Shop() {
        delete[] products;
        cout << "Shop destroyed\n";
    }
};

#endif