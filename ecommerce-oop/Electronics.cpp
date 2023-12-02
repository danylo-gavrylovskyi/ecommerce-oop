#include "Electronics.h"

Electronics::Electronics(string name, double price, int quantityInStock, string brand, string model, string powerConsumption) : brand(brand), model(model), powerConsumption(powerConsumption) {
	this->name = name;
	this->price = price;
	this->quantityInStock = quantityInStock;
}

void Electronics::operator = (Electronics&& another) {
	this->name = another.name;
	this->price = another.price;
	this->quantityInStock = another.quantityInStock;
	this->brand = another.brand;
	this->model = another.model;
	this->powerConsumption = another.powerConsumption;

	another.name = "";
	another.price = 0;
	another.quantityInStock = 0;
	another.brand = "";
	another.model = "";
	another.powerConsumption = "";
}

string Electronics::getBrand() const {
	return this->brand;
}
string Electronics::getModel() const {
	return this->model;
}
string Electronics::getPowerConsumption() const {
	return this->powerConsumption;
}

void Electronics::setBrand(string brand) {
	this->brand = brand;
}
void Electronics::setModel(string model) {
	this->model = model;
}
void Electronics::setPowerConsumption(string powerConsumption) {
	this->powerConsumption = powerConsumption;
}

void Electronics::displayDetails() const {
	cout << "Electronics, " << this->productID << "," << this->name << ", " << this->price << "," << this->brand << "," << this->model << "," << this->powerConsumption << endl;
}
