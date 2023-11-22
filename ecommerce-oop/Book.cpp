#include "Book.h"

Book::Book(string author, string genre, int ISBN): author(author), genre(genre), ISBN(ISBN) {}

string Book::getAutor() const {
	return this->author;
}
string Book::getGenre() const {
	return this->genre;
}
int Book::getISBN() const {
	return this->ISBN;
}
