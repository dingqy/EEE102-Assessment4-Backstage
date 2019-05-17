#include <iostream>
#include "sqlite3.h"
#include "Console.h"
#include <map>
#pragma comment(lib, "sqlite3.lib")

using namespace std;

void addBook() {
	Console temp = Console();
	Book book1 = Book("Algorithms", "0", "Wayne", "Princeton", "Stored", 40.0);
	temp.addBook(book1);
	Book book2 = Book("Modern Semiconductor Devices for Integrated Circuits", "978-7-03-032665-2", "Chengming Hu", "Beijing", "Stored", 88.0);
	temp.addBook(book2);
	temp.exit();
}

void addUser() {
	Console temp = Console();
	Admin adm1 = Admin(1716584, "Admin1", "Male");
	temp.addUser(adm1, "admin", "password");
	temp.exit();
}

void borrowBook() {
	Console temp;
	User usr1 = temp.login("dingqy100", "dingqy123");
	map<string, string> type;
	type["Name"] = "Semiconductor";
	vector<Book> booksearch1 = temp.searchBook(type);
	temp.borrowBook(booksearch1[0], usr1);
	temp.exit();
}

void returnBook() {
	Console temp;
	map<string, string> type;
	type["Name"] = "Semiconductor";
	vector<Book> booksearch1 = temp.searchBook(type);
	temp.returnBook(booksearch1[0]);
	temp.exit();
}

void ReserveBook() {
	Console temp;
	User usr1 = temp.login("admin", "password");
	map<string, string> type;
	type["Name"] = "Semiconductor";
	vector<Book> booksearch1 = temp.searchBook(type);
	temp.bookReserve(booksearch1[0], usr1);
	temp.exit();
}

void Reserve_borrow() {
	Console temp;
	map<string, string> type;
	User usr1 = temp.login("dingqy", "123123");
	type["Name"] = "Semiconductor";
	vector<Book> booksearch1 = temp.searchBook(type);
	temp.returnBook(booksearch1[0]);
	temp.borrowBook(booksearch1[0], usr1);
}

void getFine() {
	Console temp;
	map<string, string> type;
	User usr1 = temp.login("dingqy", "123123");
	type["Name"] = "Semiconductor";
	vector<Book> booksearch1 = temp.searchBook(type);
	cout << temp.getFine(booksearch1[0]);
}

int main() {
	//addBook();
	//addUser();
	returnBook();
	//ReserveBook();
	borrowBook();
	getFine();
	//Reserve_borrow();
}
