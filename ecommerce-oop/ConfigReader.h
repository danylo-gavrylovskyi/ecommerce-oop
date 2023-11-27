#pragma once

#include <string>
#include <vector>

#include "Inventory.h"

using namespace std;

class IConfigReader {
	virtual void loadConfig(const char* fileName) = 0;
	virtual void readConfig(Inventory& inventory) = 0;
};

class ConfigReader : public IConfigReader {
	string config = "";
	vector<string> split(const string& text, char delimeter);
public:
	void loadConfig(const char* fileName) override;
	void readConfig(Inventory& inventory) override;
};
