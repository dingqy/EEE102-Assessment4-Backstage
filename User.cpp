#include "User.h"
#include <iostream>
#include <string>

User::User(int id, string name, string gender, int bookBorrow) {
	this->id = id;
	this->name = name;
	this->gender = gender;
	this->permission = 0;
	this->bookBorrow = bookBorrow;
}

int User::getId() {
	return id;
}

string User::getName() {
	return name;
}

string User::getGender() {
	return gender;
}

int User::getBookBorrow() {
	return bookBorrow;
}

int User::getBookReserve() {
	return bookReserve;
}

void User::setId(int id) {
	this->id = id;
}

void User::setName(string name) {
	this->name = name;
}

void User::setGender(string gender) {
	this->gender = gender;
}

int User::getPermission() {
	return permission;
}

bool User::isFull() {
	return false;
}

Admin::Admin(int id, string name, string gender, int bookborrow) {
	this->id = id;
	this->name = name;
	this->gender = gender;
	this->empty = false;
	this->permission = 1;
	this->bookBorrow = bookborrow;
}

bool Admin::isFull() {
	return true;
}

Student::Student(int id, string name, string gender, int bookborrow) {
	this->id = id;
	this->name = name;
	this->gender = gender;
	this->empty = false;
	this->permission = 2;
}

Staff::Staff(int id, string name, string gender, int bookborrow) {
	this->id = id;
	this->name = name;
	this->gender = gender;
	this->permission = 3;
}

bool Student::isFull() {
	return this->bookBorrow >= 6;
}

bool Staff::isFull() {
	return this->bookBorrow >= 30;
}
