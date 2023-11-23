#pragma once

#include "Product.h"

class Book : public Product {
	string author;
	string genre;
	string ISBN;
public:
	Book(string author, string genre, string ISBN, string name, double price);
	Book(const Book&) = delete;
	Book(Book&&) = delete;

	string getAutor() const;
	string getGenre() const;
	string getISBN() const;

	void displayDetails() const override;
};
