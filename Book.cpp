#include "Book.h"

Book::Book(string name, string author, string publisher, int bookId, string bookCondition, string dueTime, double price) {
	this->name = name;
	this->author = author;
	this->publisher = publisher;
	this->bookId = bookId;
	this->bookCondition = bookCondition;
	this->borrowTime = dueTime;
	this->price = price;
}

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
