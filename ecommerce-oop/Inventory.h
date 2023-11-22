#pragma once

#include <vector>
#include "Product.h"

class Inventory {
	vector<Product> products;
public:
	Inventory(const vector<Product>& products);
	Inventory(const Inventory&) = delete;
	Inventory(Inventory&&) = delete;

	void changeProductQuantity(const int& productId, const int& newQuantity);
	void showRestockList() const;
};
