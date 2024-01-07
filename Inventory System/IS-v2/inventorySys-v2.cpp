#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Product {
public:
    std::string name;
    int quantity;
    double price;

    Product(std::string n, int q, double p) : name(n), quantity(q), price(p) {}

    void display() const {
        std::cout << "Name: " << name << "\nQuantity: " << quantity << "\nPrice: $" << price << "\n";
    }

    // Convert product information to string for file I/O
    std::string toString() const {
        return name + ", " + std::to_string(quantity) + ", " + std::to_string(price);
    }
};

class Inventory {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void displayInventory() const {
        std::cout << "Inventory:\n";
        for (const auto& product : products) {
            product.display();
            std::cout << "-----------------------\n";
        }
    }

    // Save inventory to a text file
    void saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& product : products) {
                outFile << product.toString() << "\n";
            }
            outFile.close();
            std::cout << "Inventory saved to " << filename << "\n";
        } else {
            std::cerr << "Error opening file for writing\n";
        }
    }

    // Load inventory from a text file
    void loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            std::string line;
            while (std::getline(inFile, line)) {
                // Parse the line and create a product
                size_t pos1 = line.find(",");
                size_t pos2 = line.find(",", pos1 + 1);

                std::string name = line.substr(0, pos1);
                int quantity = std::stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
                double price = std::stod(line.substr(pos2 + 1));

                Product product(name, quantity, price);
                addProduct(product);
            }
            inFile.close();
            std::cout << "Inventory loaded from " << filename << "\n";
        } else {
            std::cerr << "Error opening file for reading\n";
        }
    }
};

int main() {
    Inventory inventory;

    // Load initial inventory from a text file
    inventory.loadFromFile("inventory.txt");

    // Display the initial inventory
    inventory.displayInventory();

    // Adding a new product to the inventory
    Product newProduct1("Baby-Dinosaur_RescueCenter", 1, 39.99);
    Product newProduct2("Visitor_Center:T-rex_&_Raptor_Attack", 1, 129.99);
    Product newProduct3("Brachiosaurus-Discovery", 1, 79.99);
    Product newProduct4("T-rex_Dinosaur_Breakout", 1, 49.99);
    Product newProduct5("Dinosaur_Fossils:T-rex_Skull", 1, 39.99);

    inventory.addProduct(newProduct1);
    inventory.addProduct(newProduct2);
    inventory.addProduct(newProduct3);
    inventory.addProduct(newProduct4);
    inventory.addProduct(newProduct5);

    // Save the updated inventory to a new text file
    inventory.saveToFile("updated_inventory.txt");

    return 0;
}
