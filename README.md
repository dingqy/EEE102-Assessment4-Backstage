# EEE102 Spring 2019 Assessment 4

## Project Name
Library Management System

## Development Environment
Visual Studio 2019

## Update
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
