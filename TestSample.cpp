#include <iostream>
#include "sqlite3.h"
#include "Console.h"
#include <map>
#pragma comment(lib, "sqlite3.lib")

using namespace std;



int main() {
	User user1 = User();
	Console temp = Console();
	Book temp2 = Book("Algorithms", "Wayne", "Princeton", 1, "Stored", "0", 40.0);
	temp.addBook(temp2);
	temp2 = Book("Computer Systems12", "Patt", "UTAustin", 3, "Stored", "0", 40.0);
	temp.addBook(temp2);
	map<string, string> temp3;
	temp3["Name"] = "Computer";
	vector<Book> temp4 = temp.searchBook(temp3);
	cout <<  temp4[0].getName() << " " << temp4[0].getBorrowTime() << endl;
	map<string, string> temp6;
	vector<User> temp5 = temp.searchUser(temp6);
	cout << temp5[0].getName() << " " << temp5[0].getGender() << endl;
	Student stu1 = Student(1717573, "dingqy144", "Male");
	temp.addUser(stu1, "dingqy100", "dingqy123");

	if (temp.login("dingqy", "12123").empty) {
		cout << "No user / Wrong input" << endl;
	} else {
		cout << "Log in successfully" << endl;
	}
	user1 = temp.login("dingqy", "123123");
	if (!temp.borrowBook(temp2, user1)) {
		cout << "Can not borrow" << endl;
	}
	cout << temp.getFine(temp4[1]) << endl;
	//temp.returnBook(temp2);
	temp.exit();
	/*sqlite3* db;
	int res = sqlite3_open("test.db", &db);
	if (res != SQLITE_OK) {
		cout << "fail!" << sqlite3_errmsg(db) << endl;
		return 0;
	} else {
		cout << "success" << endl;
	}

	char sql[] = "CREATE TABLE COMPANY("  \
		"ID INT PRIMARY KEY     NOT NULL," \
		"NAME           TEXT    NOT NULL," \
		"AGE            INT     NOT NULL," \
		"ADDRESS        CHAR(50)," \
		"SALARY         REAL );";
	char* zErrMsg = 0;
	res = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if (res == SQLITE_OK) {
		cout << "success";
	} else {
		cout << "fail:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
	}

	sqlite3_close(db);*/

}