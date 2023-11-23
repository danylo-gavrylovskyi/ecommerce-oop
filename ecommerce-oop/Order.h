#pragma once

#include <string>
#include <vector>
#include "Product.h"
using namespace std;

class Order {
	static int s_currentId;
	int orderId;
	string customer;
	vector<Product*> products;
	double totalCost;
	string orderStatus;
public:
	Order();
	Order(const vector<Product*> products, const string& customer, const double& totalCost, const string& orderStatus);
	Order(const Order&) = delete;
	Order(Order&&) = delete;

	void addProduct(Product* product);
	double calculateTotalCost() const;
	void displayOrder() const;
	void setOrderStatus(const string& newStatus);
};
