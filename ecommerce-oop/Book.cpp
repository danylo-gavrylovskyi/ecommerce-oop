#include "Book.h"

Book::Book(string author, string genre, string ISBN, string name, double price): author(author), genre(genre), ISBN(ISBN) {
	this->name = name;
	this->price = price;
}

string Book::getAutor() const {
	return this->author;
}
string Book::getGenre() const {
	return this->genre;
}
string Book::getISBN() const {
	return this->ISBN;
}

void Book::displayDetails() const {
	cout << "Book, " << this->productID << ", " << this->name << ", " << this->price << ", " << this->author << ", " << this->genre << ", " << this->ISBN << endl;
}
