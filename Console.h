//
// Copyright [2019] <Copyright Qiyang Ding>
//

#include <ctime>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "Book.h"
#include "User.h"
#include "sqlite3.h"
#include "stdlib.h"
using namespace std;

#ifndef ASSESSMENT4_Console_H_
#define ASSESSMENT4_Console_H_

// Control the channel between sqlite3 and C++
// As the backstage of all the library system
class Console {
 private:
  sqlite3* db;

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
  bool deleteUser(Book book);
  bool bookReserve(Book book, User user);
  int getFine(Book book);
  void exit();
};

#endif  // ASSESSMENT4_Console_H
