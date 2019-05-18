#include "Book.h"

Book::Book(string name, string isbn, string author, string publisher, string bookCondition, double price, int bookId, string dueTime, int reserveId) {
	this->name = name;
	this->author = author;
	this->publisher = publisher;
	this->bookId = bookId;
	this->bookCondition = bookCondition;
	this->borrowTime = dueTime;
	this->price = price;
	this->isbn = isbn;
	this->reserveId = reserveId;
}

/*Book::Book(string name, string isbn, string author, string publisher, string bookCondition, double price, int reserveId, int bookId, string dueTime) {
	this->name = name;
	this->author = author;
	this->publisher = publisher;
	this->bookId = bookId;
	this->bookCondition = bookCondition;
	this->borrowTime = dueTime;
	this->price = price;
	this->isbn = isbn;
	this->reserveId = reserveId;
}*/

string Book::getName() {
	return name;
}

string Book::getIsbn() {
	return isbn;
}

string Book::getAuthor() {
	return author;
}

double Book::getPrice() {
	return this->price;
}

string Book::getPublisher() {
	return publisher;
}

string Book::getBookCondition() {
	return bookCondition;
}

string Book::getWarehousingTime() {
	return warehousingTime;
}

string Book::getBorrowTime() {
	return borrowTime;
}

int Book::getBookId() {
	return bookId;
}

int Book::getReserveId() {
	return reserveId;
}
