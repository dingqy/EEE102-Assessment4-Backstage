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
	
public:
	User() = default;
	User(int id, string name, string gender);
	int getId();
	string getName();
	string getGender();
	void setId(int id);
	void setName(string name);
	void setGender(string gender);
	int getPermission();
	bool empty = true;
};

class Admin : public User {
public:
	Admin(int id, string name, string gender);
};

class Student : public User {
public:
	Student(int id, string name, string gender);
};

#endif
