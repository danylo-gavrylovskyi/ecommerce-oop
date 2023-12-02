#include "Order.h"

int Order::s_currentId = 0;

Order::Order(){
	this->orderId = s_currentId++;
	this->totalCost = 0;
}

Order::Order(const vector<Product*> products, const string& customer, const double& totalCost, const string& orderStatus) {
	this->orderId = s_currentId++;
	this->products = products;
	this->customer = customer;
	this->totalCost = totalCost;
	this->orderStatus = orderStatus;
}

Order::Order(Order&& another) {
	this->orderId = another.orderId;
	this->customer = another.customer;
	this->products = another.products;
	this->totalCost = another.totalCost;

	another.orderId = 0;
	another.customer = "";
	another.products = {};
	another.totalCost = 0;
}

Order::~Order() {
	for (const auto& product : this->products) {
		delete product;
	}
}

void Order::operator = (const Order& another) {
	this->orderId = another.orderId;
	this->customer = another.customer;
	this->products = another.products;
	this->totalCost = another.totalCost;
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

string Order::getCustomer() const {
	return this->customer;
}
int Order::getOrderId() const {
	return this->orderId;
}

void Order::setOrderStatus(const string& newStatus) {
	this->orderStatus = newStatus;
}
void Order::setCustomer(string&& customer) {
	this->customer = move(customer);
}
void Order::setTotalCost(const double& totalCost) {
	this->totalCost = totalCost;
}
