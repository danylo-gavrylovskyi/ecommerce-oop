#pragma once

#include "Product.h"

class Electronics : public Product {
	string brand;
	string model;
	string powerConsumption;
public:
	Electronics(string brand, string model, string powerConsumption, string name, double price);
	Electronics(const Electronics&) = delete;
	Electronics(Electronics&&) = delete;

	string getBrand() const;
	string getModel() const;
	string getPowerConsumption() const;

	void displayDetails() const override;
};

