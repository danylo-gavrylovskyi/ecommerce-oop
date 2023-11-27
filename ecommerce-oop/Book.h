#pragma once

#include "Product.h"

class Book : public Product {
	string author;
	string genre;
	string ISBN;
public:
	Book(string name, double price, int quantityInStock, string author, string genre, string ISBN);
	Book(const Book&) = delete;
	Book(Book&&) = delete;

	string getAutor() const;
	string getGenre() const;
	string getISBN() const;

	void displayDetails() const override;
};
