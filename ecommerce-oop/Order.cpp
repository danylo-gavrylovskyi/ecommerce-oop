#include "Order.h"

int Order::s_currentId = 0;

Order::Order(){
	this->orderId = 0;
	this->totalCost = 0;
}

Order::Order(const vector<Product*> products, const string& customer, const double& totalCost, const string& orderStatus) {
	this->products = products;
	this->customer = customer;
	this->totalCost = totalCost;
	this->orderStatus = orderStatus;
}

Order::~Order() {
	for (const auto& product : this->products) {
		delete product;
	}
}

void Order::addProduct(Product* product) {
	this->products.push_back(product);
}

double Order::calculateTotalCost() const {
	double totalCost = 0;
	for (const Product* product : this->products) {
		totalCost += product->getPrice();
	}
	return totalCost;
}

void Order::displayOrder() const {
	for (const auto& product : this->products) {
		product->displayDetails();
	}
}

void Order::setOrderStatus(const string& newStatus) {
	this->orderStatus = newStatus;
}
