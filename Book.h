#include <iostream>
#include <string>
using namespace std;

#ifndef ASSESSMENT4_book
#define ASSESSMENT4_book

class Book {
private:
	string name;
	string isbn;
	string author;
	string publisher;
	int bookId;
	string bookCondition;
	string warehousingTime;
	string borrowTime;
public:
	Book(string name, string author, string publisher, int bookId);
	Book(string name, string isbn, string author, string publisher, int bookId, string bookCondition, string warehousingTime, string borrowTime);
	string getName();
	string getIsbn();
	string getAuthor();
	string getPublisher();
	string getBookCondition();
	string getWarehousingTime();
	string getBorrowTime();
	int getBookId();
};

#endif
