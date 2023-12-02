#include "Book.h"

Book::Book(string name, double price, int quantityInStock, string author, string genre, string ISBN): author(author), genre(genre), ISBN(ISBN) {
	this->name = name;
	this->price = price;
	this->quantityInStock = quantityInStock;
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

void Book::setAutor(string author) {
	this->author = author;
}
void Book::setGenre(string genre) {
	this->genre = genre;
}
void Book::setISBN(string ISBN) {
	this->ISBN = ISBN;
}

void Book::displayDetails() const {
	cout << "Book, " << this->productID << "," << this->name << ", " << this->price << "," << this->author << "," << this->genre << "," << this->ISBN << endl;
}
