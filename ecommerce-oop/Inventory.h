#pragma once

#include <vector>
#include "Product.h"

class Inventory {
	vector<Product*> products = {};
public:
	Inventory();
	Inventory(const Inventory&) = delete;
	Inventory(Inventory&&) = delete;
	~Inventory();

	void addProduct(Product* product);
	void displayProducts() const;
	void changeProductQuantity(const int& productId, const int& newQuantity);
	void showRestockList() const;
};
