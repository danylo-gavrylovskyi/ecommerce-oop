#pragma once

#include <string>
#include <iostream>

using namespace std;

class IProduct {
	virtual int getProductId() const = 0;
	virtual string getName() const = 0;
	virtual double getPrice() const = 0;
	virtual int getQuantityInStock() const = 0;

	virtual void setName(string name) = 0;
	virtual void setPrice(double price) = 0;
	virtual void setQuantityInStock(int quantityInStock) = 0;

	virtual void displayDetails() const = 0;
};

class Product : public IProduct {
	static int s_id;
protected:
	int productID;
	string name;
	double price;
	int quantityInStock;
public:
	Product();
	Product(string name, double price, int quantityInStock);
	Product(const Product& another);
	Product(Product&& another);

	void operator= (const Product& another);

	int getProductId() const override;
	string getName() const override;
	double getPrice() const override;
	int getQuantityInStock() const override;

	void setName(string name) override;
	void setPrice(double price) override;
	void setQuantityInStock(int quantityInStock) override;

	virtual void displayDetails() const override;
};
