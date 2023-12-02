#pragma once

#include <vector>

#include "Product.h"
#include "Electronics.h"
#include "Book.h"
#include "Clothing.h"

class Inventory {
	vector<Product*> products = {};

	void changeElectronic(int& choice, Electronics* electronicsProduct);
	void changeClothing(int& choice, Clothing* clothingProduct);
	void changeBook(int& choice, Book* bookProduct);
public:
	Inventory();
	Inventory(const Inventory&) = delete;
	Inventory(Inventory&&) = delete;
	~Inventory();

	void addProduct(Product* product);
	void updateProductDetails(const int& productId);
	void removeProduct(const int& productId);
	void displayProducts() const;
	void filterByCategory(const int& category) const;

	void changeProductQuantity(const int& productId, const int& newQuantity);
	void showRestockList() const;

	vector<Product*> getProducts() const;
};
