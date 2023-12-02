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

	void operator = (Electronics&&);

	string getBrand() const;
	string getModel() const;
	string getPowerConsumption() const;

	void setBrand(string brand);
	void setModel(string model);
	void setPowerConsumption(string powerConsumption);

	void displayDetails() const override;
};

