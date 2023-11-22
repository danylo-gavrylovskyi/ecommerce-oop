#pragma once

#include "Product.h"

class Book : public Product {
	string author;
	string genre;
	int ISBN;
public:
	Book(string author, string genre, int ISBN);
	Book(const Book&) = delete;
	Book(Book&&) = delete;

	string getAutor() const;
	string getGenre() const;
	int getISBN() const;
};
