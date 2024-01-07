#include <iostream>
#include <vector>
#include <string>

// Product class to represent each product
class Product {
public:
    std::string name;
    int quantity;
    double price;

    // Constructor
    Product(std::string n, int q, double p) : name(n), quantity(q), price(p) {}

    // Display product information
    void display() const {
        std::cout << "Name: " << name << "\nQuantity: " << quantity << "\nPrice: $" << price << "\n";
    }
};

// Inventory class to manage products
class Inventory {
private:
    std::vector<Product> products;

public:
    // Add a new product to the inventory
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    // Display all products in the inventory
    void displayInventory() const {
        std::cout << "Inventory:\n";
        for (const auto& product : products) {
            product.display();
            std::cout << "-----------------------\n";
        }
    }
};

int main() {
    // Example usage
    Inventory inventory;

    // Adding products to the inventory
    Product product1("Laptop", 10, 799.99);
    Product product2("Smartphone", 20, 399.99);

    inventory.addProduct(product1);
    inventory.addProduct(product2);

    // Displaying the inventory
    inventory.displayInventory();

    return 0;
}
