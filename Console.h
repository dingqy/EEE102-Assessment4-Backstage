#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include "stdlib.h"
#include "sqlite3.h"
#include "User.h"
#include "Book.h"
#include "SearchType.h"
using namespace std;

#ifndef ASSESSMENT4_console
#define ASSESSMENT4_console

class Console {
private:
	sqlite3* db;
public:
	Console();
	User login(string username, string password);
	vector<Book> searchBook(map<string, string> type);
	vector<User> searchUser(SearchType temp);
	bool addBook(Book book);
	bool addUser(User user);
	bool updateUser(User user);
	bool updateBook(Book book);
	bool borrowBook(Book book, User user);
	bool returnBook(Book book, User user);
};

#endif
