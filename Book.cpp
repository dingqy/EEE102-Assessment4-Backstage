//
// Copyright [2019] <Copyright Qiyang Ding>
//

#include "Book.h"
#include <string>

Book::Book(string name, string isbn, string author, string publisher,
           string bookCondition, double price, int bookId, string dueTime,
           int reserveId) {
  this->name = name;
  this->author = author;
  this->publisher = publisher;
  this->bookId = bookId;
  this->bookCondition = bookCondition;
  this->dueTime = dueTime;
  this->price = price;
  this->isbn = isbn;
  this->reserveId = reserveId;
}

string Book::getName() { return name; }

string Book::getIsbn() { return isbn; }

string Book::getAuthor() { return author; }

double Book::getPrice() { return this->price; }

string Book::getPublisher() { return publisher; }

string Book::getBookCondition() { return bookCondition; }

string Book::getBorrowTime() { return dueTime; }

int Book::getBookId() { return bookId; }

int Book::getReserveId() { return reserveId; }

void Book::setName(string name) { this->name = name; }

void Book::setIsbn(string isbn) { this->isbn = isbn; }

void Book::setPrice(double price) { this->price = price; }

void Book::setAuthor(string author) { this->author = author; }

void Book::setPublisher(string publisher) { this->publisher = publisher; }
