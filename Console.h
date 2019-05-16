#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include "stdlib.h"
#include "sqlite3.h"
#include "User.h"
#include "Book.h"
using namespace std;

#ifndef ASSESSMENT4_console
#define ASSESSMENT4_console

class Console {
private:
	sqlite3* db;
	int cache_BookId = 0;
public:
	Console();
	User login(string username, string password);
	vector<Book> searchBook(map<string, string> type);
	vector<User> searchUser(map<string, string> type);
	bool addBook(Book book);
	bool addUser(User user, string username, string password);
	bool updateUser(User user);
	bool updateBook(Book book);
	bool borrowBook(Book book, User user);
	bool returnBook(Book book);
	bool deleteBook(Book book);
	bool deleteUser(User user);
	bool bookReverse(Book book, User user);
	int getFine(Book book);
	void exit();
};

#endif
