#include "Console.h"

//Execute the sql sentences
bool sqlExecute(string sqlTemp, sqlite3* db) {
	char* zErrMsg = 0;
	int res = sqlite3_exec(db, sqlTemp.c_str(), 0, 0, &zErrMsg);
	if (res == SQLITE_OK) {
		cout << "success";
		return true;
	} else {
		cout << "fail:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		return false;
	}
}

//Get specfic dates
string getTime() {
	//%H:%M:%S	
	time_t second;
	time(&second);

	tm localTm;
	localtime_s(&localTm, &second);

	localTm.tm_mon += 1;
	localTm.tm_mday = 28;

	char localTimeStr[128] = { 0 };
	strftime(localTimeStr, sizeof(localTimeStr), "%F", &localTm);

	return localTimeStr;
}

//Open the sqlite3
Console::Console() {
	int res = sqlite3_open("test.db", &db);
	if (res != SQLITE_OK) {
		cout << "fail!" << sqlite3_errmsg(db) << endl;
	} else {
		cout << "success" << endl;
	}
}

//Login the system
User Console::login(string username, string password) {
	ostringstream ostr1;
	ostr1 << "SELECT Id, Name, Gender FROM User WHERE " << "Username = '" << username << "' AND Password = '" << password << "';";
	int id = 0;
	string name;
	string gender;
	char* errmsg;
	char** pResult;
	int nRow;
	int nCol;
	int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow, &nCol, &errmsg);
	if (nResult != SQLITE_OK) {
		sqlite3_close(db);
		cout << errmsg << endl;
		sqlite3_free(errmsg);
		return User();
	}
	if (nRow == 0) {
		return User();
	}
	int index = nCol;
	for (int i = 0; i < nRow; i++) {
		id = atoi(pResult[index]);
		index++;
		name = pResult[index];
		index++;
		gender = pResult[index];
		index++;
	}
	return Admin(id, name, gender);
}

//Search the books from database (Name should be the first)
vector<Book> Console::searchBook(map<string, string> type) {
	vector<Book> result;
	ostringstream ostr1;
	ostr1 << "SELECT Name, Author, Publisher, BookId, BookCondition, dueTime FROM Book";
	if (!type.empty()) {
		ostr1 << " WHERE";
		map<string, string>::iterator iter = type.begin();
		ostr1 << " " << iter->first << " LIKE '%" << iter->second << "%";
		iter ++;
		while (iter != type.end()) {
			ostr1 << "'AND " << iter->first << " = '" << iter->second;
			iter ++;
		}
		ostr1 << "';";
	}
	string name;
	string author;
	string publisher;
	int bookId;
	string bookCondition;
	string dueTime;
	string temp = ostr1.str();
	char* errmsg;
	char** pResult;
	int nRow;
	int nCol;
	int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow, &nCol, &errmsg);
	if (nResult != SQLITE_OK) {
		sqlite3_close(db);
		cout << errmsg << endl;
		sqlite3_free(errmsg);
		return result;
	}
	int index = nCol;
	for (int i = 0; i < nRow; i++) {
		name = pResult[index];
		index++;
		author = pResult[index];
		index++;
		publisher = pResult[index];
		index++;
		bookId = atoi(pResult[index]);
		index++;
		bookCondition = pResult[index];
		index++;
		dueTime = pResult[index];
		index++;
		result.push_back(Book(name, author, publisher, bookId, bookCondition, dueTime));
	}
	return result;
}

//Add the book to the database
bool Console::addBook(Book book) {
	ostringstream ostr1;
	ostr1 << "INSERT INTO BOOK VALUES ('" << book.getName() << "', '"
		<< book.getAuthor() << "', '" << book.getPublisher() << "', " << book.getBookId() << ", '"
		<< book.getBookCondition() << "', 0, '0');";
	return sqlExecute(ostr1.str(), db);
}

//Add the user to the database
bool Console::addUser(User user) {
	ostringstream ostr1;
	ostr1 << "INSERT INTO User VALUES (" << user.getId() << ", '"
		<< user.getName() << "', '" << user.getGender() << "');";
	return sqlExecute(ostr1.str(), db);
}

//Update the user in the database
bool Console::updateUser(User user) {
	ostringstream ostr1;
	ostr1 << "UPDATE User SET Id =  " << user.getId() << ", Name = '"
		<< user.getName() << "', Gender = '" << user.getGender() << "' WHERE Id = " << user.getId() << ";";
	return sqlExecute(ostr1.str(), db);
}

//Update the book in the database
bool Console::updateBook(Book book) {
	ostringstream ostr1;
	ostr1 << "UPDATE Book SET Name =  '" << book.getName() << "', Author = '" 
		<< book.getAuthor() << "', Publisher = '" << book.getPublisher() << "' WHERE bookId = " << book.getBookId() << ";";
	return sqlExecute(ostr1.str(), db);
}

//User borrow the book (dueTime was next month 28)
bool Console::borrowBook(Book book, User user) {
	ostringstream ostr1;
	ostr1 << "SELECT * FROM Book WHERE BookId = " << book.getBookId() << " AND BookCondition = '" << "Stored';";
	char* errmsg;
	char** pResult;
	int nRow;
	int nCol;
	int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow, &nCol, &errmsg);
	if (nResult != SQLITE_OK) {
		sqlite3_close(db);
		cout << errmsg << endl;
		sqlite3_free(errmsg);
		return false;
	}
	if (nRow == 0) {
		return false;
	}
	ostr1.str("");
	ostr1 << "UPDATE Book SET bookCondition =  'On loan-due', borrowId = "<< user.getId() << ", dueTime = '" << getTime() << "' WHERE bookId = " << book.getBookId() << ";";
	return sqlExecute(ostr1.str(), db);
}

bool Console::returnBook(Book book) {
	ostringstream ostr1;
	ostr1 << "SELECT * FROM Book WHERE BookId = " << book.getBookId() << " AND BookCondition = '" << "On loan-due';";
	char* errmsg;
	char** pResult;
	int nRow;
	int nCol;
	int nResult = sqlite3_get_table(db, ostr1.str().c_str(), &pResult, &nRow, &nCol, &errmsg);
	if (nResult != SQLITE_OK) {
		sqlite3_close(db);
		cout << errmsg << endl;
		sqlite3_free(errmsg);
		return false;
	}
	if (nRow == 0) {
		return false;
	}
	ostr1.str("");
	ostr1 << "UPDATE Book SET bookCondition =  'Stored', borrowId = 0, dueTime = '0' WHERE bookId = " << book.getBookId() << ";";
	return sqlExecute(ostr1.str(), db);
}

//Exit the system
void Console::exit() {
	sqlite3_close(db);
}

