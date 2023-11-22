#include "Product.h"

Product::Product(string name, double price, int quantityInStock) : productID(s_id++), name(name), price(price), quantityInStock(quantityInStock) {}

int Product::getProductId() const {
	return this->productID;
}
string Product::getName() const {
	return this->name;
}
double Product::getPrice() const {
	return this->price;
}
int Product::getQuantityInStock() const {
	return this->quantityInStock;
}

void Product::setName(string name) {
	this->name = name;
}
void Product::setPrice(double price) {
	this->price = price;
}
void Product::setQuantityInStock(int quantityInStock) {
	this->quantityInStock = quantityInStock;
}
