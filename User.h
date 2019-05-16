#include <iostream>
#include <string>
using namespace std;

#ifndef ASSESSMENT4_user
#define ASSESSMENT4_user

class User {
protected:
	int id;
	string name;
	string gender;
	int permission;
	int bookBorrow;
	int bookReserve;
	
public:
	User() = default;
	User(int id, string name, string gender, int bookBorrow, int bookReverse);
	int getId();
	string getName();
	string getGender();
	int getBookBorrow();
	int getBookReserve();
	void setId(int id);
	void setName(string name);
	void setGender(string gender);
	int getPermission();
	bool empty = true;
	virtual bool isFull();
	bool isFullReverse();
};

class Admin : public User {
public:
	Admin(int id, string name, string gender, int bookborrow=0, int bookReverse=0);
	bool isFull();
};

class Student : public User {
public:
	Student(int id, string name, string gender, int bookborrow = 0, int bookReverse = 0);
	bool isFull();
};

class Staff : public User {
public:
	Staff(int id, string name, string gender, int bookborrow=0, int bookReverse=0);
	bool isFull();
};

#endif
