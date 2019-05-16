# EEE102 Spring 2019 Assessment 4

## Project Name
Library Management System

## Development Environment
Visual Studio 2019

## Update
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
* Return the user with empty == true if successfully loging in.
* Otherwise, return the user with empty == false.
#### 2. bool addBook (Book book)
* Return true if adding successfully
#### 3. bool addUser (User user)
* Return true if adding successfully
#### 4. bool updateBook (Book book)
* Return true if adding successfully
#### 5. bool updateUser (User user)
* Return true if adding successfully
#### 6. bool borrowBook (Book book)
* Return true if borrowing book successfully
#### 7. bool returnBook (Book book)
* Return true if returning book successfully
#### 8. vector<Book> searchBook (map<string, string> type)
* Return vector<Book> that contains all the book fulfill the requrements.
* If no books fulfill the requirements, vector<Book> will be empty
* Map has been built in the std library and it can be created directly.
* In the future, the creation map will be replaced by easier way.
