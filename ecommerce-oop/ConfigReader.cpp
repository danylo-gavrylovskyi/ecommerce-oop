#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "ConfigReader.h"
#include "Electronics.h"
#include "Book.h"
#include "Clothing.h"

using namespace std;

void ConfigReader::loadConfig(const char* fileName) {
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            this->config += "\n" + line;
        }
        myfile.close();
    }

    else cout << "Unable to open file";
}

void ConfigReader::readConfig(Inventory& inventory) {
    if (this->config.empty()) {
        cout << "Error: no config found";
        return;
    }

    vector<string> lines = split(this->config, '\n');

    for (string line : lines) {
        vector<string> dataLine = split(line, ',');
        if (dataLine.size() == 0) continue;

        if (dataLine[0] == "Electronics") inventory.addProduct(new Electronics(dataLine[1], stod(dataLine[2]), stoi(dataLine[3]), dataLine[4], dataLine[5], dataLine[6]));
        if (dataLine[0] == "Clothing") inventory.addProduct(new Clothing(dataLine[1], stod(dataLine[2]), stoi(dataLine[3]), dataLine[4], dataLine[5], dataLine[6]));
        if (dataLine[0] == "Books") inventory.addProduct(new Book(dataLine[1], stod(dataLine[2]), stoi(dataLine[3]), dataLine[4], dataLine[5], dataLine[6]));
    }
}

vector<string> ConfigReader::split(const string& text, char delimeter) {
    istringstream iss(text);

    vector<string> lines = {};

    string line;
    while (getline(iss, line, delimeter)) {
        lines.push_back(move(line));
    }

    return lines;
}