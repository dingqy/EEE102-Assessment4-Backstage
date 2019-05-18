# EEE102 Spring 2019 Assessment 4

## Project Name
Library Management System

## Development Environment
Visual Studio 2019 + SQLite + DB Brower for SQLite

## Qt installation
1. Right click the program in the Qt creator
2. Choose Adding the library
3. Choose the second option and add the sqlite3.lib
4. When adding the library, please do not choose the option like "Debug suffix d"
5. Rebuild the program
6. Change "test.db" into absolute path in the constructor of Console

## Update
### Version 1.2.0
#### Date: 2019 / 05 / 17
* Fix some bugs
* Rewrite the test example

### Version 1.1.0
#### Date: 2019 / 05 / 16
* Fix some bugs
* reverseBook() can be used now
* deleteBook() and deleteUser() can be used now
* bookId will be added automatically

### Version 1.0.0
#### Date: 2019 / 05 / 15
* Fix some bugs
* searchUser() can be used now
* Login() will create different User according to the permission in the database
* Each user has their own limit of borrowing books
* User class has a new child: Staff
* getFine() can be used to get whether the user have to pay for the delay of returning books
* Book now has a new attribute: price (The price of the book)

### Version 0.2.0
#### Date: 2019 / 05 / 09
* Fix some bugs and simplify some code
* searchBook() support vague name search
* The person who borrow the book can be recoreded as borrowId in the database
* The returnTime can be recoreded as dueTime in the database

### Version 0.1.0
#### Date: 2019 / 05 / 05
* Achieve login function
* Achieve addBook and addUser function
* Achieve updateBook and updateUser function
* Achieve searchBook function <br>
Notice: The program haven't passed the automatic unit test

## Class Function Introduction
### Class Console
#### 1. User login (string name, string password)
* Return User whose permission is 0 if failing to log in
* Return Admin (permission == 1), Student (permission == 2), Staff (permission == 3) if logging in successfully
#### 2. bool addBook (Book book)
* book: name, author, publisher, bookCondition ("Stored"), price, isbn
* Return true if adding successfully
#### 3. bool addUser (User user, string username, string password)
* user: Id, name, gender, permission
* Return true if adding successfully
#### 4. bool updateBook (Book book)
* Notice: this method first need to use searchBook() to get the bookId of the book
* book: name, author, publisher, price, isbn
* Return true if adding successfully
#### 5. bool updateUser (User user)
* Notice: this method first need to use searchUser() to get the Id of the user (Login is also available)
* user: name, gender (It will be updated in the future)
* Return true if adding successfully
* This method cannot change the username and password.
#### 6. bool borrowBook (Book book, User user)
* Notice: this method first need to use searchBook() to get the bookId of the book
* book: bookId
* user: Id
* Return true if borrowing book successfully
#### 7. bool returnBook (Book book)
* Notice: this method first need to use searchBook() to get the bookId of the book
* book: bookId
* Return true if returning book successfully
#### 8. vector<Book> searchBook (map<string, string> type)
* Return vector<Book> that contains all the book fulfill the requrements.
* If no books fulfill the requirements, vector<Book> will be empty
* Map has been built in the std library and it can be created directly.
* The book returned in the vector contains all the detailed information
#### 9. vector<User> searchUser (map<string, string> type)
* Return vector<User> that contains all the book fulfill the requrements.
* If no users fulfill the requirements, vector<Book> will be empty
* Map has been built in the std library and it can be created directly.
* The user returned in the vector contains all the detailed information except username and password.
#### 10. bool bookReserve(Book book, User user)
* Notice: this method first need to use searchBook() to get the bookId of the book
* Return true if book is reversed
#### 11. bool deleteBook(Book book)
* Notice: this method first need to use searchBook() to get the bookId of the book
* book: bookId
* Return true if book is deleted
#### 12. bool deleteUser(User user)
* Notice: this method first need to use searchUser() to get the Id of the user (Should not use login())
* user: Id
* Return true if user is deleted
#### 13. int getFine(Book book)
* Notice: this method first need to use searchBook() to get the bookId of the book
* This method should be used before return the book
* Return integer of whether the book need to be paid for delay
### Class User
* addBookBorrow() and addBookReserve() should be used after Console.addBookBorrow() or Console.bookReserve()
* Otherwise, you need to search or login the user again to get the newest information
