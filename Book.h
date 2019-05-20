//
// Copyright [2019] <Copyright Qiyang Ding>
//

#include <iostream>
#include <string>
using namespace std;

#ifndef ASSESSMENT4_Book_H_
#define ASSESSMENT4_Book_H_

// Store all the information of books
class Book {
 private:
  string name;
  string isbn;
  string author;
  string publisher;
  int bookId;
  string bookCondition;
  string dueTime;
  int reserveId;
  double price;

 public:
  Book(string name, string isbn, string author, string publisher,
       string bookCondition, double price, int bookId = 0, string dueTime = "0",
       int reserveId = 0);
  string getName();
  string getIsbn();
  string getAuthor();
  double getPrice();
  string getPublisher();
  string getBookCondition();
  string getBorrowTime();
  int getBookId();
  int getReserveId();
  void setName(string name);
  void setIsbn(string isbn);
  void setPrice(double price);
  void setAuthor(string author);
  void setPublisher(string publisher);
};

#endif  // ASSESSMENT4_Book_H
