#include "Clothing.h"

Clothing::Clothing(string size, string color, string material, string name, double price): size(size), color(color), material(material) {
	this->name = name;
	this->price = price;
}

string Clothing::getSize() const {
	return this->size;
}
string Clothing::getColor() const {
	return this->color;
}
string Clothing::getMaterial() const {
	return this->material;
}

void Clothing::displayDetails() const {
	cout << "Clothing, " << this->productID << ", " << this->name << ", " << this->price << ", " << this->size << ", " << this->color << ", " << this->material << endl;
}
