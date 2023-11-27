#pragma once

#include "Product.h"

class Clothing: public Product {
	string size;
	string color;
	string material;
public:
	Clothing(string name, double price, int quantityInStock, string size, string color, string material);
	Clothing(const Clothing&) = delete;
	Clothing(Clothing&&) = delete;

	string getSize() const;
	string getColor() const;
	string getMaterial() const;

	void displayDetails() const override;
};
