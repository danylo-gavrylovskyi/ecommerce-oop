#include <iostream>
#include "Inventory.h"

Inventory::Inventory(){}

Inventory::~Inventory() {
    for (const auto& product : this->products) {
        delete product;
    }
}

void Inventory::addProduct(Product* product) {
    this->products.push_back(product);
}

void Inventory::displayProducts() const {
    for (const auto& product : this->products) {
        product->displayDetails();
    }
}

void Inventory::changeProductQuantity(const int& productId, const int& newQuantity) {
    auto it = find_if(this->products.begin(), this->products.end(), [productId](const Product* product) {return product->getProductId() == productId; });

    if (it != this->products.end())
    {
        this->products[it - this->products.begin()]->setQuantityInStock(newQuantity);
    }
    else {
        cout << "Product not found.\n\n";
    }
}

void Inventory::showRestockList() const {
    for (const auto& product : this->products) {
        if (product->getQuantityInStock() < 10) {
            cout << product->getName() << " with ID '" << product->getProductId() << "' left only " << product->getQuantityInStock() << " in stock";
        }
    }
}
