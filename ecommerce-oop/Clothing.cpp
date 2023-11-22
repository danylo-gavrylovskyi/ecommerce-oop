#include "Clothing.h"

Clothing::Clothing(string size, string color, string material): size(size), color(color), material(material) {}

string Clothing::getSize() const {
	return this->size;
}
string Clothing::getColor() const {
	return this->color;
}
string Clothing::getMaterial() const {
	return this->material;
}
