//
// Copyright [2019] <Copyright Qiyang Ding>
//

#include "User.h"
#include <iostream>
#include <string>

User::User(string name, string gender, int bookBorrow, int bookReserve) {
  this->name = name;
  this->gender = gender;
  this->permission = 0;
  this->bookBorrow = bookBorrow;
  this->bookReserve = bookReserve;
  this->id = 0;
}

User::User(int id, string name, string gender, int bookBorrow,
           int bookReserve) {
  this->id = id;
  this->name = name;
  this->gender = gender;
  this->permission = 0;
  this->bookBorrow = bookBorrow;
  this->bookReserve = bookReserve;
}

int User::getId() { return id; }

string User::getName() { return name; }

string User::getGender() { return gender; }

int User::getBookBorrow() { return bookBorrow; }

int User::getBookReserve() { return bookReserve; }

void User::addBookBorrow(int borrow) { this->bookBorrow += borrow; }

void User::addBookReserve(int reserve) { this->bookReserve += reserve; }

void User::setId(int id) { this->id = id; }

void User::setName(string name) { this->name = name; }

void User::setGender(string gender) { this->gender = gender; }

int User::getPermission() { return permission; }

bool User::isFull() { return false; }

bool User::isFullReserve() { return this->bookReserve > 3; }

Admin::Admin(int id, string name, string gender, int bookborrow,
             int bookReserve) {
  this->id = id;
  this->name = name;
  this->gender = gender;
  this->permission = 1;
  this->bookBorrow = bookborrow;
  this->bookReserve = bookReserve;
}

bool Admin::isFull() { return false; }

Student::Student(int id, string name, string gender, int bookborrow,
                 int bookReserve) {
  this->id = id;
  this->name = name;
  this->gender = gender;
  this->permission = 2;
  this->bookBorrow = bookborrow;
  this->bookReserve = bookReserve;
}

Staff::Staff(int id, string name, string gender, int bookborrow,
             int bookReserve) {
  this->id = id;
  this->name = name;
  this->gender = gender;
  this->bookBorrow = bookborrow;
  this->permission = 3;
  this->bookReserve = bookReserve;
}

bool Student::isFull() { return this->bookBorrow >= 6; }

bool Staff::isFull() { return this->bookBorrow >= 30; }
