#include "Electronics.h"

Electronics::Electronics(string brand, string model, string powerConsumption) : brand(brand), model(model), powerConsumption(powerConsumption) {}

string Electronics::getBrand() const {
	return this->brand;
}
string Electronics::getModel() const {
	return this->model;
}
string Electronics::getPowerConsumption() const {
	return this->powerConsumption;
}
