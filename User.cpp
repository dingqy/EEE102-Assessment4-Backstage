#include "User.h"
#include <iostream>
#include <string>

User::User(int id, string name, string gender) {
	this->id = id;
	this->name = name;
	this->gender = gender;
	this->permission = 0;
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

int User::getPermission() {
	return permission;
}

Admin::Admin(int id, string name, string gender) {
	this->id = id;
	this->name = name;
	this->gender = gender;
	this->permission = 1;
}

Student::Student(int id, string name, string gender) {
	this->id = id;
	this->name = name;
	this->gender = gender;
	this->permission = 2;
}
