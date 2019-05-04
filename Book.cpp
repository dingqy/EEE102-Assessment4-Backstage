#include "Book.h"

Book::Book(string name, string author, string publisher, int bookId) {
	this->name = name;
	this->author = author;
	this->publisher = publisher;
	this->bookId = bookId;
}

Book::Book(string name, string isbn, string author, string publisher, int bookId, string bookCondition, string warehousingTime, string borrowTime) {
	this->name = name;
	this->author = author;
	this->publisher = publisher;
	this->bookId = bookId;
	this->bookCondition = bookCondition;
	this->warehousingTime = warehousingTime;
	this->borrowTime = borrowTime;
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
