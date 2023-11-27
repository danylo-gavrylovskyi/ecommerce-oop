#include "Electronics.h"

Electronics::Electronics(string name, double price, int quantityInStock, string brand, string model, string powerConsumption) : brand(brand), model(model), powerConsumption(powerConsumption) {
	this->name = name;
	this->price = price;
	this->quantityInStock = quantityInStock;
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

void Electronics::displayDetails() const {
	cout << "Electronics, " << this->productID << "," << this->name << ", " << this->price << "," << this->brand << "," << this->model << "," << this->powerConsumption << endl;
}
