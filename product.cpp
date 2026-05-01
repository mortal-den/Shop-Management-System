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
    Product() {
        id = 0;
        name = "Unknown";
        price = 0.0;
        quantity = 0;
    }
    Product(int i, string n, float p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }


    Product(const Product &p) {
        id = p.id;
        name = p.name;
        price = p.price;
        quantity = p.quantity;
    }

  
    void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

  
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

   
    operator float() const {
        return price;
    }

    float operator+(Product p) {
        return this->price + p.price;
    }

 
    ~Product() {
         cout << "Product destroyed\n";
    }
};