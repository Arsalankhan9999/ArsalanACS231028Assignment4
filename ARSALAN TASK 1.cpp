#include <iostream>
#include <vector>
#include <algorithm>

struct Product {
    int id;
    std::string name;
    // Add other product details as needed
};

std::vector<Product> inventory;

void addProduct(int id, const std::string& name) {
    // Check if the product already exists based on ID
    for (const auto& product : inventory) {
        if (product.id == id) {
            std::cout << "Product with ID " << id << " already exists.\n";
            return;
        }
    }

    // If the product doesn't exist, add it to the inventory
    inventory.push_back({id, name});
    std::cout << "Product added to the inventory.\n";
}

void removeProduct(int id) {
    // Use erase-remove idiom to remove the product based on ID
    auto it = std::remove_if(inventory.begin(), inventory.end(),
                             [id](const Product& product) { return product.id == id; });

    // Check if a product was removed
    if (it != inventory.end()) {
        inventory.erase(it, inventory.end());
        std::cout << "Product with ID " << id << " removed from the inventory.\n";
    } else {
        std::cout << "Product with ID " << id << " not found in the inventory.\n";
    }
}

int main() {
    // Example usage
    addProduct(1, "Laptop");
    addProduct(2, "Smartphone");
    addProduct(3, "Tablet");

    removeProduct(2);

    return 0;
}

