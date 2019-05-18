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
	string warehousingTime; //Unused
	string borrowTime; // It is dueTime
	int reserveId;
	double price;
public:
	//Book(string name, string isbn, string author, string publisher, string bookCondition, double price, int reserveId, int bookId = 0, string dueTime = "0");
	Book(string name, string isbn, string author, string publisher, string bookCondition, double price, int bookId=0, string dueTime="0", int reserveId=0);
	string getName();
	string getIsbn();
	string getAuthor();
	double getPrice();
	string getPublisher();
	string getBookCondition();
	string getWarehousingTime();
	string getBorrowTime();
	int getBookId();
	int getReserveId();
};

#endif
