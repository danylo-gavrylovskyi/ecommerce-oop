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

void Inventory::updateProductDetails(const int& productId) {
    auto it = find_if(this->products.begin(), this->products.end(), [productId](const Product* product) {return product->getProductId() == productId; });

    if (it != this->products.end())
    {
        Electronics* electronicsProduct = dynamic_cast<Electronics*>(*it);
        Clothing* clothingProduct = dynamic_cast<Clothing*>(*it);
        Book* bookProduct = dynamic_cast<Book*>(*it);

        int choice = 0;

        if (electronicsProduct) {
            changeElectronic(choice, electronicsProduct);
            this->products[it - this->products.begin()] = electronicsProduct;
            delete clothingProduct;
            delete bookProduct;
        }
        else if (clothingProduct) {
            changeClothing(choice, clothingProduct);
            this->products[it - this->products.begin()] = clothingProduct;
            delete electronicsProduct;
            delete bookProduct;
        }
        else if (bookProduct) {
            changeBook(choice, bookProduct);
            this->products[it - this->products.begin()] = bookProduct;
            delete electronicsProduct;
            delete clothingProduct;
        }
    }
    else {
        cout << "Product not found.\n\n";
    }
}

void Inventory::removeProduct(const int& productId) {
    this->products.erase(std::remove_if(this->products.begin(), this->products.end(),
        [productId](const auto& product) { return product->getProductId() == productId; }));
}

void Inventory::displayProducts() const {
    for (const auto& product : this->products) {
        cout << product->getQuantityInStock() << " left in stock -> ";
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

vector<Product*> Inventory::getProducts() const {
    return this->products;
}

void Inventory::changeElectronic(int& choice, Electronics* electronicsProduct) {
    while (true) {
        cout << "What do you want to change:\n\t0. Exit\n\t1. Price\n\t2. Brand\n\t3. Model\n\t4. Power consumption\n>>";
        cin >> choice;
        if (choice == 0) break;

        switch (choice)
        {
        case 1: {
            double newPrice;
            cout << "Enter updated price: ";
            cin >> newPrice;
            electronicsProduct->setPrice(move(newPrice));
            break;
        }
        case 2: {
            string newBrand;
            cout << "Enter updated brand: ";
            cin >> newBrand;
            electronicsProduct->setBrand(move(newBrand));
            break;
        }
        case 3: {
            string newModel;
            cout << "Enter updated model: ";
            cin >> newModel;
            electronicsProduct->setModel(move(newModel));
            break;
        }
        case 4: {
            string newPowerConsumption;
            cout << "Enter updated power consumption: ";
            cin >> newPowerConsumption;
            electronicsProduct->setPowerConsumption(move(newPowerConsumption));
            break;
        }
        default:
            break;
        }
    }
}
void Inventory::changeClothing(int& choice, Clothing* clothingProduct) {
    while (true) {
        cout << "What do you want to change:\n\t0. Exit\n\t1. Price\n\t2. Size\n\t3. Color\n\t4. Material\n>>";
        cin >> choice;
        if (choice == 0) break;

        switch (choice)
        {
        case 1: {
            double newPrice;
            cout << "Enter updated price: ";
            cin >> newPrice;
            clothingProduct->setPrice(move(newPrice));
            break;
        }
        case 2: {
            string newSize;
            cout << "Enter updated size: ";
            cin >> newSize;
            clothingProduct->setSize(move(newSize));
            break;
        }
        case 3: {
            string newColor;
            cout << "Enter updated color: ";
            cin >> newColor;
            clothingProduct->setColor(move(newColor));
            break;
        }
        case 4: {
            string newMaterial;
            cout << "Enter updated material: ";
            cin >> newMaterial;
            clothingProduct->setMaterial(move(newMaterial));
            break;
        }
        default:
            break;
        }
    }
}
void Inventory::changeBook(int& choice, Book* bookProduct) {
    while (true) {
        cout << "What do you want to change:\n\t0. Exit\n\t1. Price\n\t2. Author\n\t3. Genre\n\t4. ISBN\n>>";
        cin >> choice;
        if (choice == 0) break;

        switch (choice)
        {
        case 1: {
            double newPrice;
            cout << "Enter updated price: ";
            cin >> newPrice;
            bookProduct->setPrice(move(newPrice));
            break;
        }
        case 2: {
            string newAuthor;
            cout << "Enter updated author: ";
            cin >> newAuthor;
            bookProduct->setAutor(move(newAuthor));
            break;
        }
        case 3: {
            string newGenre;
            cout << "Enter updated genre: ";
            cin >> newGenre;
            bookProduct->setGenre(move(newGenre));
            break;
        }
        case 4: {
            string ISBN;
            cout << "Enter updated ISBN: ";
            cin >> ISBN;
            bookProduct->setISBN(move(ISBN));
            break;
        }
        default:
            break;
        }
    }
}
