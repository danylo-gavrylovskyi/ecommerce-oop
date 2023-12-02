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
	Order(Order&&);
	~Order();

	void operator = (const Order&);

	void addProduct(Product* product);
	double calculateTotalCost() const;
	void displayOrder() const;

	string getCustomer() const;
	int getOrderId() const;

	void setOrderStatus(const string& newStatus);
	void setCustomer(string&& customer);
	void setTotalCost(const double& totalCost);
};
