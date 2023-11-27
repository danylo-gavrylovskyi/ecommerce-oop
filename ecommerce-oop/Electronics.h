#pragma once

#include "Product.h"

class Electronics : public Product {
	string brand;
	string model;
	string powerConsumption;
public:
	Electronics(string name, double price, int quantityInStock, string brand, string model, string powerConsumption);
	Electronics(const Electronics&) = delete;
	Electronics(Electronics&&) = delete;

	string getBrand() const;
	string getModel() const;
	string getPowerConsumption() const;

	void displayDetails() const override;
};

