#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;
    int quantity;

public:
    // Default Constructor
    Product() {
        id = 0;
        name = "Unknown";
        price = 0.0;
        quantity = 0;
    }

    // Parameterized Constructor
    Product(int i, string n, float p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    // Copy Constructor
    Product(const Product &p) {
        id = p.id;
        name = p.name;
        price = p.price;
        quantity = p.quantity;
    }

    // Display Function
    void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    // Input Function
    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    // 🔥 Getter for ID
    int getId() const {
        return id;
    }

    // 🔥 Getter for Quantity
    int getQuantity() const {
        return quantity;
    }

    // 🔥 Setter for Quantity
    void setQuantity(int q) {
        quantity = q;
    }

    // Data Conversion (Product → float)
    operator float() const {
        return price;
    }

    // Operator Overloading (+)
    float operator+(Product p) {
        return this->price + p.price;
    }

    // Destructor
    ~Product() {
        cout << "Product destroyed\n";
    }
};