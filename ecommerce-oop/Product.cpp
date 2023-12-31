#include "Product.h"

int Product::s_id = 0;

Product::Product(){
	this->name = "";
	this->price = 0;
	this->productID = s_id++;
	this->quantityInStock = 0;
}
Product::Product(const Product& another) {
	this->name = another.name;
	this->price = another.price;
	this->productID = another.productID;
	this->quantityInStock = another.quantityInStock;
}
Product::Product(string name, double price, int quantityInStock) : productID(s_id++), name(name), price(price), quantityInStock(quantityInStock) {}

void Product::operator= (const Product& another) {
	this->name = another.name;
	this->price = another.price;
	this->productID = another.productID;
	this->quantityInStock = another.quantityInStock;
}

Product::Product(Product&& another) {
	this->name = another.name;
	this->price = another.price;
	this->productID = another.productID;
	this->quantityInStock = another.quantityInStock;

	another.name = "";
	another.price = 0;
	another.productID = 0;
	another.quantityInStock = 0;
}

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

void Product::displayDetails() const {
	cout << "Product, " << this->productID << ", " << this->name << ", " << this->price << ", " << this->quantityInStock << endl;
}
